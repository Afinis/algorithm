#include<bits/stdc++.h>
using namespace std;
const int MAX = 500000+5, EXP = 25;
int n, m, s;
struct node{
	int last, to;
}e[2*MAX];
int head[MAX], c;
int fa[MAX][EXP+5], dep[MAX];

void add(int x, int y){
	e[++c].to = y;
	e[c].last = head[x];
	head[x] = c;
}

void dfs(int i, int p){
	dep[i] = dep[p] + 1;
	fa[i][0] = p;
	for(int j = 1; j < EXP; j++){
		fa[i][j] = fa[fa[i][j-1]][j-1]; 
	}
	for(int j = head[i]; j; j = e[j].last){
		if(e[j].to != p)
			dfs(e[j].to, i);
	}
}

int lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	int t = dep[y] - dep[x];
	for(int i = 0; t; ++i, t>>=1){
		if(t&1) y = fa[y][i];
	}
	if(x == y) return x;
	for(int i = EXP; i >= 0 && x != y; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

int main(){
	scanf("%d%d%d", &n, &m, &s);	
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x,&y);
		add(x, y);
		add(y, x);
	}
	dfs(s, 0);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x,&y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}
