#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
ll n, m, k, a[N], b[N];

bool check(ll x){
	ll c = 0;
	for(int i = 1; i <= n; i++){
		c += upper_bound(b+1, b+1+m, x-a[i]) - b - 1;
	}
	return c >= k;
}

int main(){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld", &b[i]);
	}
	sort(b+1, b+m+1);
	ll lo = 1, hi = 2e9+1;
	while(lo < hi){
		ll mi = lo + hi >> 1;
		if(check(mi)){
			hi = mi;
		}else{
			lo = mi+1;
		}
	}
	printf("%lld\n", lo);
	return 0;
}
