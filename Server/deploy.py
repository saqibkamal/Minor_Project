from flask import Flask,jsonify,request
import string
import base64
from PIL import Image
from io import BytesIO



app = Flask(__name__)

@app.route("/predict",methods=['POST'])
def predict():
	
	content = request.get_json()
	im = Image.open(BytesIO(base64.b64decode(content["image"])))
	im.save('image.jpg')
	return jsonify("Test Successful")




if __name__ == '__main__':
	app.run()
 



