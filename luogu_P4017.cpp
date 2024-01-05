#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5000+5], mx, ind[5000+5], outd[5000+5]; 
ll n, m;
unordered_map<int, vector<int> > mp;
ll dfs(int x){
	if(dp[x] > 0) return dp[x];
	for(int i = 0; i < mp[x].size(); i++){
		dp[x] += dfs(mp[x][i]);
		dp[x] %= 80112002;
	}
	return 0 == dp[x] ? 1 : dp[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		ind[v]++;
		outd[u]++;
		mp[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		if(ind[i] ==0)
			mx += dfs(i);
			mx %= 80112002;
	}
	printf("%lld", mx%80112002);
	return 0;
}
