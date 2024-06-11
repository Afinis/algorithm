#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, m, g[N][N], w[N];
int d[N], vis[N];

void dij(){
	fill(d, d+N, N*N);
	d[1] = 0;
	
	for(int i = 1; i < n; i++){
		int u = -1, mi = N*N;
		for(int j = 1; j <= n; j++){
			if(mi > d[j] && !vis[j] ){
				u = j;
				mi = d[j];
			}
		}
		if(u == -1) break;
		vis[u] = 1;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && g[u][j]){
				d[j] = min(d[j], g[u][j] + d[u]);
			}
		}
	}
	
}

int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>w[i];
	}
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin>>u>>v>>c;
		g[u][v] = c + w[v];
		g[v][u] = c + w[u];
	}
	dij();
	cout<<d[n]-w[n]<<endl;
	return 0;
}
