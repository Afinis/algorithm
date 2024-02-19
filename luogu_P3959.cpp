#include<bits/stdc++.h>
using namespace std;
int n, m, g[20][20], trans[1<<13][1<<13];
long long dp[20][1<<13], ans;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		x--; y--;
		if(g[x][y]==0 || g[x][y] > v){
			g[x][y] = v;
			g[y][x] = v;
		}
	}
	m = (1 << n);
	
	for(int i = 1; i < m; i++)
	// j是i的子集 
	for(int j = i; j; j = (j-1)&i){
		int t = i^j; // 异或 
		int en = 0;
		for(int k = n-1; k >= 0; k--)
			if(t & (1<<k)){
				int d = 0;
				for(int u = 0; u < n; u++)			
					if((j & (1<<u)) && g[u][k])
						d = d==0? g[u][k] : min(d, g[u][k]);		
				if (d==0){
					en=1;
					break;
				}
				trans[j][i] += d;
			}
		if(en) trans[j][i] = 0;
	}
	
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
    	dp[0][1<<i]=0;
	for(int i = 1; i < n; i++)
	for(int j = 0; j < m; j++)
	for(int k=j; k; k=(k-1)&j)
		if(trans[k][j] && dp[i-1][k]!=-1 && trans[k][j]){
			long long t = dp[i-1][k]+trans[k][j]*i;
			dp[i][j] = dp[i][j]==-1? t : min(t, dp[i][j]);
		}	

	for(int i=1; i<n; i++)
		if(dp[i][m-1] > 0)
			ans = ans==0? dp[i][m-1]: min(dp[i][m-1], ans);
	printf("%lld", ans);
	return 0;
}
