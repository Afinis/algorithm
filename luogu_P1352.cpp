#include<bits/stdc++.h>
using namespace std;
const int M = 6*1000+5, inf = -10000000 ;
int n, r[M], fa[M], dp[M][2];
vector<int> son[M];

void dfs(int i){
	if(dp[i][0] != inf) return;
	if(son[i].empty()){
		dp[i][0] = 0;
		dp[i][1] = r[i];
		return;
	}
	int t = 0, t2 = 0;
	for(int j = 0; j < son[i].size(); j++){
		dfs(son[i][j]);
		t += max(dp[son[i][j]][0], dp[son[i][j]][1]);
		t2 += dp[son[i][j]][0];
	}
	dp[i][0] = t;
	dp[i][1] = t2+r[i];
}

int main(){
	fill(dp[0], dp[01]+M*2, inf);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &r[i]);	
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		son[v].push_back(u);
		fa[u] = v;
	}
	for(int i = 1; i <= n; i++){
		if(fa[i] == 0) dfs(i);	
	}
	int ans = max(dp[1][0], dp[1][1]);
	for(int i = 2; i <= n; i++){
		int t = max(dp[i][0], dp[i][1]);
		ans = max(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}
