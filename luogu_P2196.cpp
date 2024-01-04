#include<bits/stdc++.h>
using namespace std;

int dp[25], n, e[25], g[25][25], pre[25], r, mx;

void dfs(int t){
	if(t == 0) return;
	dfs(pre[t]);
	printf("%d", t);
	if(t != r) printf(" ");
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &e[i]);	
	
	for(int i = 1; i <= n-1; i++)
		for(int j = i+1; j <= n; j++)
			scanf("%d", &g[i][j]);	
	
	for(int i = 1; i <= n; i++){
		dp[i] = e[i]; 
		if(dp[i] > mx){
			mx = dp[i];
			r = i;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i-1; j++){
			if(g[j][i] && dp[i] < dp[j] + e[i]){
				dp[i] = dp[j] + e[i];
				pre[i] = j;
				if(dp[i] > mx){
					mx = dp[i];
					r = i;
				}
			}
		}
	}
	dfs(r);
	printf("\n%d", mx);
	return 0;
}
