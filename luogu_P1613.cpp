#include<bits/stdc++.h>
using namespace std;
// dp[i][j][k]表示从i到j是否存在一条长度为2^k的路径; g记录两点之间需要用多久到达
int dp[60][60][65], g[60][60], n, m;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = 1;
		dp[u][v][0]=1; 
	}
	for(int k = 1; k < 64; k++)
	for(int u = 1; u <= n; u++)
	for(int v = 1; v <= n; v++)
	for(int c = 1; c <= n; c++){
		if(dp[u][c][k-1]&&dp[c][v][k-1]){
			dp[u][v][k] = 1;
			g[u][v] = 1;
		}
	}
	
	for(int k = 1; k <= n; k++)
	for(int u = 1; u <= n; u++)
	for(int v = 1; v <= n; v++){
		if(g[u][k]&&g[k][v]&& (g[u][v]>g[u][k]+g[k][v] || g[u][v]==0))
			g[u][v] = g[u][k]+g[k][v];
	}
	printf("%d\n", g[1][n]);
	return 0;
}
