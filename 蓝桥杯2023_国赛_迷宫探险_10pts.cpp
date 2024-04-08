#include<bits/stdc++.h>
using namespace std;
int n, m, hp, t[30], ec, head[30], vis[30], ans=1e7;
struct node{
	int to, last, w;
}e[3000];

void add(int u, int v, int w){
	e[++ec].to = v;
	e[ec].w = w;
	e[ec].last = head[u];
	head[u] = ec;
}

int hppp(int u){
	int r = 0;
	if(vis[u]) return 0;
	for(int i = head[u]; i; i = e[i].last){
		int v = e[i].to;
		if(vis[v]) continue;
		r += t[v];
	}
	return r;
}
void dfs(int i, int W, int HP, int num, int k){
	if(k>n+1) return;
	if(num == n && i==n-1){
		if(ans > W) ans = W;
		return;
	}
	if(W > ans) return;
	for(int j = head[i]; j ; j = e[j].last){		
		int v = e[j].to;
		int th = hppp(v);
		if(!vis[v]){
			if(HP-th > 0){
				vis[v] = 1;
				dfs(v, W+e[j].w, HP-th, num+1, 0);
				vis[v] = 0;
			}	
		}else{
			dfs(v, W+e[j].w, HP, num, k+1);
		}
	}
}

int main(){
	cin>>n>>m>>hp;
	for(int i = 0; i < n; i++) cin>>t[i];
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(0, 0, hp, 0, 0);
	if(ans==1e7) cout<<-1<<endl; 
	else cout<<ans<<endl;
	return 0;
}
