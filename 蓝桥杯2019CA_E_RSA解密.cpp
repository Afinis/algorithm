#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 1001733993063167141, n2 = 1001733993063167141;
ll sn, p, q, d=212353, c=20190324;

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x = 1, y = 0;
		return a;
	}
	ll g = exgcd(b, a%b, x, y);
	ll t = x;
	x = y;
	y = t-(a/b)*y;
	return g; 
}

ll fast_mul(ll a, ll b){
	ll ans=0;
	while(b){
		if(b&1){
			ans = (ans+a)%n2;
		}
		a = (a << 1)%n2;
		b >>= 1;
	}
	return ans%n2;
}

ll fast_pow(ll x, ll p){
	ll t = x, r = 1;
	while(p){
		if(p&1){
			r = fast_mul(r, t);
		}
		t = fast_mul(t, t);
		p>>=1;
	}
	return r%n2;
}

int main(){	
	sn=sqrt(n);
	for(ll i = 2; i < sn+100; i++){
		if(n%i==0){
			p=i;
			n/=i;
		}
	}
	q = n;
	ll x=0, y=0, t = (p-1)*(q-1);
	exgcd(d, t, x, y);
	ll e = (x%t+t)%t; // x没有溢出，只是恰好为负数 
	cout<<p<<endl;
	cout<<q<<endl;
	cout<<p*q<<endl;
	cout<<x<<endl;
	cout<<e<<endl;
	cout<<fast_pow(c, e)<<endl;
	return 0;
}
