import dlib
import scipy.misc
import numpy as np
import os

from flask import Flask,jsonify,request
import string
import base64
from PIL import Image
from io import BytesIO

#hello
# Get Face Detector from dlib
# This allows us to detect faces in images
face_detector = dlib.get_frontal_face_detector()

# Get Pose Predictor from dlib
# This allows us to detect landmark points in faces and understand the pose/angle of the face
shape_predictor = dlib.shape_predictor('shape_predictor_68_face_landmarks.dat')

# Get the face recognition model
# This is what gives us the face encodings (numbers that identify the face of a particular person)
face_recognition_model = dlib.face_recognition_model_v1('dlib_face_recognition_resnet_model_v1.dat')


# This function will take an image and return its face encodings using the neural network
def get_face_encodings(path_to_image):
    # Load image using scipy
    image = scipy.misc.imread(path_to_image)

    # Detect faces using the face detector
    detected_faces = face_detector(image, 1)

    # Get pose/landmarks of those faces
    # Will be used as an input to the function that computes face encodings
    # This allows the neural network to be able to produce similar numbers for faces of the same people, regardless of camera angle and/or face positioning in the image
    shapes_faces = [shape_predictor(image, face) for face in detected_faces]

    # For every face detected, compute the face encodings
    return [np.array(face_recognition_model.compute_face_descriptor(image, face_pose, 1)) for face_pose in shapes_faces]

    # This function takes a list of known faces
def train_model():


    # Get path to all the known images
    # Filtering on .jpg extension - so this will only work with JPEG images ending with .jpg
    image_filenames = filter(lambda x: x.endswith('.jpg'), os.listdir('images/'))

    # Sort in alphabetical order
    image_filenames = sorted(image_filenames)

    # Get full paths to images
    paths_to_images = ['images/' + x for x in image_filenames]

    # List of face encodings we have
    face_encodings = []

    # Loop over images to get the encoding one by one
    for path_to_image in paths_to_images:
        # Get face encodings from the image
        face_encodings_in_image = get_face_encodings(path_to_image)

        # Make sure there's exactly one face in the image
        if len(face_encodings_in_image) != 1:
            print("Please change image: " + path_to_image + " - it has " + str(len(face_encodings_in_image)) + " faces; it can only have one")
            exit()

        # Append the face encoding found in that image to the list of face encodings we have
        face_encodings.append(get_face_encodings(path_to_image)[0])
        names = [x[:-4] for x in image_filenames]


    np.save('face_encodings',face_encodings)
    np.save('name',names)
   
train_model()