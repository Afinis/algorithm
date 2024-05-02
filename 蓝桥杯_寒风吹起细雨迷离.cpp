#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e3+10;

ll n, m, dp[N][N], a[N]; 
ll ep[N];
int main(){
	cin>>n>>m;
	for(ll i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n, greater<ll>());
	ep[0] = 1;
	for(ll i = 1; ep[i-1] < (ll)1e17; i++){
		ep[i] = 2*ep[i-1];
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			for(ll k = a[i]; k <= j; k<<=1){
				ll w = a[i] * ep[dp[i-1][j-k]];
			//	if(w < k) continue;
				if(w < a[i] * ep[dp[i-1][j-w]]){
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i-1][j-w] + 1);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
} 
