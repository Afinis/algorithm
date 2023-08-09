#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 1e5+5;
int n,m,s,t, d[N], vis[N];
vector<pair<int ,int> > g[N]; 
#define inf 0x3f3f3f3f

void dij(int st, int type){
	memset(vis, 0, sizeof(vis));
	fill(d, d+N, inf);
	d[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > q;
	q.push({d[st], st});
	
	while(!q.empty()){
		int v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		
		for(int i = 0; i < g[v].size(); i++){
			if(type==1 && v==st && g[v][i].first==s) continue;		
			if(d[g[v][i].first] > d[v] + g[v][i].second){
				d[g[v][i].first] = d[v] + g[v][i].second;
				q.push({d[g[v][i].first], g[v][i].first});
			}
		}
	}	
}

int main(){
	scanf("%d%d%d%d", &n,&m,&s,&t);
	for(int i = 1; i <= m; i++){
		int x,y,v;
		scanf("%d%d%d", &x,&y,&v);
		g[x].push_back({y, v});
		g[y].push_back({x, v});
	}
	dij(s,0);
	int dt = d[t];
	int ds = inf;
	for(int i = 0; i < g[s].size(); i++){
		dij(g[s][i].first, 1);
		ds = min(ds, g[s][i].second + d[s]);		
	}	
	int flag = ds < dt;
	if(ds >= inf) ds = -1;
	if(dt >= inf) dt = -1;
	printf("%d %d\n",ds, dt);
	if(flag) printf("Win!\n");
	else printf("Lose!\n");	
	return 0;
}

