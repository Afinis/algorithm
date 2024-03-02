#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int MAX = 100000+5, m = 998244353;
ll n, a[MAX], b[MAX], p[MAX], p1[MAX];

ll fastPow(ll x, ll e){
	ll r = 1;
	for(int i = 1; e; x = (x*x)%m, e>>=1){
		if(e&1)
			r = (r*x)%m;
	}
	return r;
}

int main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld", &a[i], &b[i]);
		p[i] = (a[i] * fastPow(b[i], m-2))%m;
		p1[i] = ((b[i] - a[i]) * fastPow(b[i], m-2))%m;
	}
	int q = p1[1], w = 1;
	for(int i = 2; i <= n; i++){
		w = (w + q)%m;
		q = (q*p1[i])%m;
	}
	printf("%lld", (w*fastPow(q, m-2))%m );
	return 0;
}
