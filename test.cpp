#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+10;
ll n, m, bound[N];
double pob, d[N], ans;
int h[N], ec;
struct node{
	int to, last;
}e[N];

void add(int u, int v){
	ec++;
	e[ec].to = v;
	e[ec].last = h[u];
	h[u] = ec;
}

void dfs(int u, int p, int bcnt){
	if(bound[u]) bcnt++;
	for(int i = h[u]; i; i = e[i].last){
		int v = e[i].to;
		if(v == p) continue;
		if(bound[u]) d[v] = d[u]+1;
		else d[v] = d[u] + pow(pob, bcnt);	
		dfs(v, u, bcnt); 
	}
}

int main(){
	cin>>n>>m>>pob;
	for(int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		add(u, v);
		add(v, u);
	}
	for(int i = 0; i < m; i++){
		int t; cin>>t;
		bound[t]++;
	}
	dfs(1, 0, 0);
	for(int i = 1; i <= n; i++){
		ans += d[i];
	}
	printf("%.2lf", ans/n+1);
	return 0;
}
