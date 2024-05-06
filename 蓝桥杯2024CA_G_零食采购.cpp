#include<bits/stdc++.h>
using namespace std;
const int N = 1e6, EXP = 20;
int n, q, c[N], d[N];
int h[N], ec, fa[N][EXP+3], r[N][EXP+3];
struct node{
	int last, to;
}e[N];

void add(int u, int v){
	ec++;
	e[ec].to = v;
	e[ec].last = h[u];
	h[u] = ec;
}

void dfs(int u, int p){
	d[u] = d[p]+1;
	fa[u][0] = p;
	r[u][0] = (1<<(c[u]-1));
	if(p) r[u][0] |= (1<<(c[p]-1));
	for(int i = 1; i < EXP; i++){
		r[u][i] = r[u][i-1] | r[fa[u][i-1]][i-1];
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	
	for(int i = h[u]; i; i = e[i].last){
		int v = e[i].to;
		if(p == v) continue;
		dfs(v, u);
	}
}

int lca(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	int t = d[x] - d[y], ans = (1<<(c[x]-1)) | (1<<(c[y]-1));
	for(int i = 1, j = 0; i <= t; i <<= 1, j++){
		if(t&i){
			ans |= r[x][j];
			x = fa[x][j];
		}
	}
	if(x == y) return ans;
	for(int i = EXP-1; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			ans |= r[x][i];
			ans |= r[y][i];
			x = fa[x][i], y = fa[y][i];
		}
	}
	return ans |= r[x][0];
}

int cal(int x){
	int ans = 0;
	while(x){
		if(x&1){
			ans++;
		}
		x >>= 1;
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	for(int i = 1; i <= q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		int ans = lca(u, v);
		ans = cal(ans); 
		printf("%d\n", ans);
	}
	return 0;
}
