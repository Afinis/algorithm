#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a, b;
};
int gcd(int a, int b){
	return b ? gcd(b, a%b):a;
}
node myadd(node a, node b){
	ll q = a.a*b.b + b.a*a.b;
	ll w = a.b * b.b;
	ll d = gcd(q, w);
	d = d<0 ? -d : d;
	a.a = q/d;
	a.b = w/d;
	return a;
}
node r, t;
int main(){
	r.a=0; r.b=1;
	ll n; scanf("%lld", &n);
	for(ll i = 0; i < n; i++){
		ll a,b,d;
		scanf("%lld/%lld", &a, &b);
		t.a = a;
		t.b = b;
		r = myadd(r, t);
	}
	if(abs(r.a) >= r.b)
		r.a%r.b==0 ? printf("%lld", r.a/r.b) : printf("%lld %lld/%lld", r.a/r.b, r.a%r.b, r.b);
	else
		r.a == 0 ? printf("0") : printf("%lld/%lld", r.a, r.b);
	return 0;
}
