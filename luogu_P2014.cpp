#include<bits/stdc++.h>
using namespace std;
const int M = 305;
int pre[M], dp[M][M][M], a[M], n, m, vis[M];
vector<int> son[M];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	for(int j = 1; j <= m; j++) dp[u][0][j] = a[u];
	for(int i = 0; i < son[u].size(); i++){
		int dpi = i+1, s = son[u][i];
		dfs(son[u][i]);
		for(int j = 1; j <= m; j++){
			for(int c = 0; c < j; c++){
				if(j == 1) dp[u][dpi][j] = a[u];
				else{
					dp[u][dpi][j] = max(dp[u][dpi-1][j-c] + dp[s][son[s].size()][c], dp[u][dpi][j]);
				}
			}
		//	printf("dp[%d][%d][%d]=%d\n", u, dpi, j, dp[u][dpi][j]);
		}	
	}	
}

int main(){
	cin>>n>>m;
	for(int v = 1; v <= n; v++){
		int u, e;
		cin>>u>>e;
		pre[v]=u;
		son[u].push_back(v);
		a[v] = e;
	}
	m++;
	dfs(0);
	cout<<dp[0][son[0].size()][m]<<endl;
	return 0;
}
