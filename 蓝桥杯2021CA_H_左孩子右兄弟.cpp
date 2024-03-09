#include<bits/stdc++.h>
using namespace std;
const int M = 1e6;
int n, dp[M], sz[M], head[M], c;
struct node{
	int to, last;
}e[M];
void add(int u, int v){
	e[++c].to = v;
	e[c].last = head[u];
	head[u] = c;
}

void dfs(int i){
	for(int j = head[i]; j; j = e[j].last){
		int v = e[j].to;
		dfs(v);
		dp[i]=max(dp[v], dp[i]);
	}
	dp[i] += sz[i];
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int v;
		scanf("%d", &v);
		add(v, i);
		sz[v]++;
	}
	dfs(1);
	printf("%d\n", dp[1]);
	return 0;
}
