#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5;
ll n, k, T, c = 1e5, ans = N, a[N], t[N], sm[N], sq[N];

bool check(ll x){
	for(ll i = 1; i <= x; i++){
		t[i] = a[i];
	}
	sort(t+1, t+x+1);
	for(ll i = 1; i <= x; i++){
		sm[i] = sm[i-1] + t[i];
		sq[i] = sq[i-1] + t[i] * t[i];
	}
	for(ll i = k; i <= x; i++){
		double sig = (sq[i]-sq[i-k])/(double)k-(sm[i]-sm[i-k])*(sm[i]-sm[i-k])/(double)(k*k);
		if(sig < T){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%lld%lld%lld", &n, &k, &T);	
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	if(n < k){
		printf("-1\n");
		return 0;
	}
	ll lo = k, hi = n+1;
	while(lo < hi){
		ll mi = lo+hi>>1;
		if(check(mi)){
			hi = mi;
		}else{
			lo = mi+1;
		}
	}
	if(lo > n){
		printf("-1\n");
	}else{
		printf("%lld\n", lo);
	}
	return 0;
}
