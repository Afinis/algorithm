#include<bits/stdc++.h>
using namespace std;
const int M = 305;
int pre[M], dp[M][M], a[M], n, m, vis[M];
vector<int> son[M];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	for(int j = 1; j <= m; j++) dp[u][j] = a[u];
	for(int i = 0; i < son[u].size(); i++){
		int dpi = i+1, s = son[u][i];
		dfs(son[u][i]);
		for(int j = m; j >= 0; j--){
			for(int c = 0; c < j; c++){
				if(j == 1) dp[u][j] = a[u];
				else{
					dp[u][j] = max(dp[u][j-c] + dp[s][c], dp[u][j]);
				}
			}
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
	cout<<dp[0][m]<<endl;
	return 0;
}
