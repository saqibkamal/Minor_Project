#include<bits/stdc++.h>
using namespace std;
int ispresent(string a,string b){
    for(int i=0;i<=a.size()-b.size();i++){
        int flag=0;
        for(int j=0;j<b.size();j++){
            if(a[i+j]!=b[j]) flag=1;
        }
        if(flag==0) return 1;
    }
    return 0;
}
#define ll long long
void getZarr(string str, ll Z[]); 
vector<ll> c;
  
// prints all occurrences of pattern in text using Z algo 
vector<ll> search(string text, string pattern) 
{ 
    // Create concatenated string "P$T" 
    string concat = pattern + "$" + text; 
    ll l = concat.length(); 
  
 
    ll Z[l]={0}; 
    getZarr(concat, Z); 

    
    c.clear();
    for (ll i = 0; i < l; ++i) 
    { 

        if (Z[i] == pattern.length()) {
            c.push_back(i-pattern.length()-1);
        }
    }
    return c;
} 
void getZarr(string str, ll Z[]) 
{ 
    ll n = str.length(); 
    ll L, R, k; 

    L = R = 0; 
    for (ll i = 1; i < n; ++i) 
    { 

        if (i > R) 
        { 
            L = R = i; 

            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
          
            k = i-L; 
  
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
  
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 
int main(){
    long long T;
    cin>>T;
    while(T--){
        string s,p;
        char c;
        long long q,x,ans=-1,i=1;
        cin>>s>>p>>q;
        ll flag1=0;
        vector<ll> v= search(s,p);
        if(v.size()==0){
            ans=0;
            flag1=1;
        }
        ll co=v.size();
        ll vv[co]={0};
        while(q--){
            cin>>x>>c;
            s[x]=c;
            for(ll j=0;j<v.size() && co;j++){
                if(s.substr(v[j],p.size())!=p && vv[j]==0){
                    vv[j]=1;
                    co--;
                }
            }
            if(flag1==0 && co==0){
                ans=i;
                flag1=1;
            }
            i++;
        }
        cout<<ans<<endl;
    }

}