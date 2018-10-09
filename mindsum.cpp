// ==========  SAQIB KAMAL ======== //
/*
   * Don't even try to understand this.
   * I wrote it, and I have no idea why it works.
   * But it does. My subconscious is that good.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff(i,m,n) for(i=m;i<n;i++)
#define bf(i,m,n) for(i=m-1;i>=n;i--)
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define all(a) a.begin(),a.end()
#define MAX_SIZE 1000001
#define llm LLONG_MAX
ll mod=1e9+7;
inline void read(int &res) {
    char c;
    while (c = getchar(), c <= ' ');
    res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        res = res * 10 + (c - '0');
}
inline void write(ll &x) {
    char buf[18], *p = buf;
    do { *p++ = '0' + x % 10; x /= 10; } while (x);
    do { putchar(*--p); } while (p > buf);
}
ll exp_pow(ll x,ll y,ll z){
	if(y<=0) return 1;
	if(x<=0) return 0;
	ll b=exp_pow(x,y/2,z);
	b=(b*b)%z;
	if(y%2==0) return b;
	return ((b*x)%z);
}
vector<bool> isprime(MAX_SIZE,true);
vector<ll> prime,SPF(MAX_SIZE);
void seive(ll n)
{
	ll i;
	isprime[0]=isprime[1]=0;
	ff(i,2,n){
		if(isprime[i]){
			prime.pb(i);
			SPF[i]=i;
		}
		for(ll j=0;j<prime.size() && i*prime[j]<n
			&& prime[j]<=SPF[i];j++){
			isprime[i*prime[j]]=false;
			SPF[i*prime[j]]=prime[j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("C:\\Users\\Saqib kamal\\Documents\\testcase.txt","r",stdin);
	lll T;
	cin>>T;
	while(T--){
		cin>>n>>d;
		
	}
	




    return 0;
}

 /*
   * If you get here, I screwed up.
   * If I screwed up, I clearly don't know what I am doing.
   * If I don't know what I am doing, and you are looking at my code...
   *   ...we are both in trouble.
   */
