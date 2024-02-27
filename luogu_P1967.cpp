#include<bits/stdc++.h>
using namespace std;
const int EXP = 20, F = 2*100000+1, E = 1000000+5;
int n, m, q, sfa[2*100000+10], pfa[2*100000+10][EXP + 5], dep[2*100000+10];
int d[2*100000+10][EXP+10];
struct edge{
	int x, y, w;
}e[3*100000+10];
int ce;

struct node{
	int to, last, w;
}a[6 * 100000 + 10];
int ca, head[2  * 100000 + 10];
void add(int u, int v, int w){
	ca++;
	a[ca].to = v;
	a[ca].last = head[u];
	a[ca].w = w;
	head[u] = ca;
	return;
}

bool mycmp(edge a, edge b){
	return a.w > b.w;
}

int findFa(int x){
	int t = x;
	while(x != sfa[x]){
		x = sfa[x];
	}
	int z = t;
	while(t != sfa[t]){
		t = sfa[t];
		sfa[z] = x;
		z = t;
	}
	return x;
}

void Union(int x, int y){
	int fx = findFa(x), fy = findFa(y);
	sfa[fx] = fy;
}

int kruskal(int nume){
	int num = 0;
	for(int i = 1; i <= n; i++)
		sfa[i] = i;
	sort(e, e+ce, mycmp);
	for(int i = 0; i < ce; i++){
		int x = e[i].x, y = e[i].y, w = e[i].w;
		if(findFa(x) != findFa(y)){
			Union(x, y);
			add(x, y, w);
			add(y, x, w);		
			if(++num == nume)
				break;
		}		
	}
	return num==nume ? 1 : 0;
}

void dfs(int i, int p){
	pfa[i][0] = p;
	dep[i] = dep[p]+1;
	for(int j = head[i]; j ; j = a[j].last){
		if(a[j].to == p){
			d[i][0] = a[j].w;
			int t1 = d[i][0];
			break;
		}
	}

	for(int j = 1; j <= EXP; j++){
		pfa[i][j] = pfa[pfa[i][j-1]][j-1];
		int t1 = d[i][j-1];
		int t2 = d[pfa[i][j-1]][j-1];
		int t3 = pfa[i][j-1];
		d[i][j] = min(d[pfa[i][j-1]][j-1], d[i][j-1]);
	}
	for(int j = head[i]; j ; j = a[j].last){
		if(a[j].to != p){
			dfs(a[j].to, i);
		}
	}

}

int lca(int x, int y){
	int w = E;
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	int t = dep[x] - dep[y];
	for(int i = 0; t; i++, t >>= 1){
		if(t & 1){
			w = min(w, d[x][i]);
			x = pfa[x][i];
		}
	}
	if(x == y) return w;
	for(int i = EXP; i>=0; i--){
		if(pfa[x][i] != pfa[y][i]){
			w = min(w, d[x][i]);
			w = min(w, d[y][i]);
			x = pfa[x][i];
			y = pfa[y][i];
		}
	}
	if(pfa[x][0] == F){
		return -1;
	}else
		return min(w, min(d[x][0], d[y][0]));
}

int main(){
	fill(d[0], d[0] + (EXP+10)*(2*100000+10), E);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &e[ce].x, &e[ce].y, &e[ce].w);
		ce++;
	}
	kruskal(n-1);
	int pre = findFa(1);
	sfa[F] = F;
	sfa[pre] = F;
	add(F, pre, E);
	add(pre, F, E);
	for(int i = 2; i <= n; i++){
		int now = findFa(i);
		if(pre != now){
			sfa[now] = F;
			add(F, now, E);
			add(now, F, E);
		}
	}
	dfs(F, F);
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		int r = lca(x, y);
		printf("%d\n", r);
	}
	return 0;
}
