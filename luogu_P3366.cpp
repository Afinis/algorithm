#include<bits/stdc++.h>
using namespace std;
int fa[5000+5];
int n, m, c;
struct edge{
	int x, y, w;
}e[2*100000+10];

bool mycmp(edge a, edge b){
	return a.w < b.w;
}

int findFa(int x){
	int t = x;
	while(x != fa[x])
		x = fa[x];
	while(t != fa[t]){
		int z = t;
		t = fa[t];
		fa[z] = x;
	}
	return x;
}

void Union(int a, int b){
	int fA = findFa(a), fB = findFa(b);
	if(fA != fB)
		fa[fA] = fB;
}

int kruskal(){
	int sum = 0, num = 0;
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	sort(e, e+c, mycmp);
	for(int i = 0; i < c; i++){
		int x = e[i].x, y = e[i].y, w = e[i].w;
		if(findFa(x) != findFa(y)){
			sum += w;
			num++;
			Union(x, y);
			if(num == n-1) break;
		}
	}
	if(num != n-1) return -1;
	else return sum;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		e[c].x = x;
		e[c].y = y;
		e[c].w = w;
		c++;
	}
	int r = kruskal();
	if(r == -1)
		printf("orz\n");
	else
		printf("%d\n", r);
	return 0;
}
