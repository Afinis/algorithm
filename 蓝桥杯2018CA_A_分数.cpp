#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n = 20;
struct frac{
	ll a, b;
};

ll gcd(ll a, ll b){
	return a == 0 ? b: gcd(b%a, a);
}

frac add(frac x, frac y){
	frac r;
	r.b = x.b*y.b;
	r.a = x.a*y.b + x.b*y.a;
	ll g = gcd(r.a, r.b);
	r.a /= g;
	r.b /= g;
	return r;
}

int main(){
	ll c = 2;
	frac x; x.a=1, x.b=1;
	for(ll i = 2; i <= n; i++){
		frac y;
		y.a=1, y.b = c;
		c*=2;
		x = add(x, y);
	}
	printf("%lld/%lld\n", x.a, x.b);
	// 1048575/524288
	
	return 0;
}
