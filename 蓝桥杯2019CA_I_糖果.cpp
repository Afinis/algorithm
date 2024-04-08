#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[105], dp[1<<21];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(ll i = 1; i <= n; i++){
		ll t=0;
		for(ll j = 0; j < k; j++){
			ll p; scanf("%d", &p);
			t |= (1<<(p-1));
		}
		a[i] = t;
	}
	fill(dp, dp+(1<<21), 10000);
	dp[0]=0;
	ll s = (1<<m)-1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= s; j++){
			dp[j|a[i]] = min(dp[j]+1, dp[j|a[i]]);				
		}
	}
	printf("%d\n", dp[s]>=10000? -1 : dp[s]);
	return 0;
}
