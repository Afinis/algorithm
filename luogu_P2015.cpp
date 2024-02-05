#include<bits/stdc++.h>
using namespace std;

struct node{
	int to, data;
};
vector<node > g[205];
int n, q, dp[105][105], vis[105];
void dfs(int i){
	if(vis[i]) return;
	vis[i] = 1;
	if(!g[i].empty() && g[i].size() != 1){
		int z = g[i].size(), l = 0, r=0;
		for(int j = 0; j < z; j++){
			if(vis[g[i][j].to] == 0){
				dfs(g[i][j].to);
				if(l == 0) l = j;
				else r = j;
			}
		}
		for(int j = 1; j <= q; j++){
			int t = 0;
			t = max(dp[g[i][l].to][j-1]+ g[i][l].data, t);
			t = max(dp[g[i][r].to][j-1]+ g[i][r].data, t);
			for(int c = 0; c <= j-2; c++){
				t = max(dp[g[i][l].to][c]+ g[i][l].data + 
							dp[g[i][r].to][j-c-2]+ g[i][r].data, t);
			}
			dp[i][j] = t;
		}
	}
}

int main(){
	cin>>n>>q;
	for(int i = 1; i < n; i++){
		int u, v, t;
		cin>>u>>v>>t;
		node q;
		q.data = t;
		q.to = v;
		g[u].push_back(q);
		q.to = u;
		g[v].push_back(q);
	}
	dfs(1);
	cout<<dp[1][q]<<endl;
	return 0;
}
