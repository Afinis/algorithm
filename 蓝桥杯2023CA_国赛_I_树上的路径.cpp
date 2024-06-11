#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0;
const int N = 1e6+10;
vector<int> v[N];

int n, L, R, d[N];

void dfs(int p, int u, int rot){
	if(p == 0){
		d[u] = 0;
	}else{
		d[u] = d[p] + 1;
	}
	if(L<=d[u] && d[u]<=R && u > rot){
		ans += d[u];
	}
	for(int i = 0; i < v[u].size(); i++){
		int to = v[u][i];
		if(to == p) continue;
		dfs(u, to, rot);
	}
}

int main(){
	scanf("%d%d%d", &n, &L, &R);
	for(int i = 2; i <= n; i++){
		int t;
		scanf("%d", &t);
		v[i].push_back(t);
		v[t].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		dfs(0, i, i);
	}
	printf("%lld", ans);
	return 0;
}
