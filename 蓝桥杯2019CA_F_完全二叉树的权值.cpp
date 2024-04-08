#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;

ll a[N], n, d[N], cd, sum[N];

void dfs(ll i){
	if(i*2+1 > n){
		return;
	}
	d[i*2] = d[i*2+1] = d[i] + 1;
	cd = max(cd, d[i*2]);
	dfs(i*2);
	dfs(i*2+1);
}

int main(){
	scanf("%lld", &n);
	for(ll i = 1; i<= n; i++){
		scanf("%lld", &a[i]);
	} 
	d[1] = 1;
	dfs(1);
	for(ll i = 1; i<= n; i++){
		sum[d[i]] += a[i];
	}
	ll ma = sum[1], ans = 1;
	for(ll i = 2; i<= cd; i++){
		if(ma < sum[i]){
			ma = sum[i];
			ans = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
