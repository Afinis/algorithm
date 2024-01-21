#include<bits/stdc++.h>
using namespace std;

int n, h[1000+5];
unordered_map<int, long long> dp[1000+5];
const int v = 2*10000, M = 998244353;
#define ONE 2*10000 + 5
#define OFF ONE+1
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &h[i]);
	}
	dp[1][ONE] = 1;
	for(int i = 2; i <= n; i++){
		dp[i][ONE] = 1;
		for(auto it = dp[i-1].begin(); it != dp[i-1].end() ;it++ ){
			dp[i][OFF] += it->second;
		}
		for(int j = 1; j < i; j++){
			if(dp[j].count(h[i] - h[j])){
				dp[i][h[i] - h[j]] += dp[j][h[i] - h[j]] + 1;
				dp[i][h[i] - h[j]] %= M;
			}else{
				dp[i][h[i] - h[j]] += 1;
				dp[i][h[i] - h[j]] %= M;
			}
		}
	}
	
	long long r = 0;
	for(auto it = dp[n].begin(); it != dp[n].end() ;it++ ){
		r += it->second;
		r %= M;
	}
	printf("%lld\n", r);
	return 0;
}
