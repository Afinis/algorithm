#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int m, n, a[N], b[N], ans=0; 
int ha[N], hb[N], ca, cb;
struct node{
	int to, last;
}ea[2*N], eb[2*N];

void adda(int u, int v){
	ca++;
	ea[ca].to = v;
	ea[ca].last = ha[u];
	ha[u] = ca;
}

void addb(int u, int v){
	cb++;
	eb[cb].to = v;
	eb[cb].last = hb[u];
	hb[u] = cb;
}

void dfs(int pa, int ua, int pb, int ub, int d){
	ans = max(d, ans);
	unordered_map<int, int > mp;
	for(int i = ha[ua]; i; i = ea[i].last){
		int v = ea[i].to;
		if(pa == v) continue;
		mp[a[v]] = v;
	}
	for(int i = hb[ub]; i; i = eb[i].last){
		int v = eb[i].to;
		if(pb == v) continue;
		if(mp.count(b[v])){
			dfs(ua, mp[b[v]], ub, v, d+1);
		}
	}
}

signed main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld", &b[i]);
	}
	for(int i = 1; i <= n-1; i++){
		int u, v;
		scanf("%lld%lld", &u, &v);
		adda(u, v);
		adda(v, u);
	}
	for(int i = 1; i <= m-1; i++){
		int u, v;
		scanf("%lld%lld", &u, &v);
		addb(u, v);
		addb(v, u);
	}
	if(a[1] == b[1])
		dfs(0, 1, 0, 1, 1);
	printf("%lld\n", ans);
	return 0;
}
