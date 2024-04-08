#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e5+10;
ll n, m, ans, tc;
struct edge{
	ll u, v, w;
}t[2*M];

bool mycmp(edge a, edge b){
	return a.w < b.w;
} 

ll fa[M];
ll findFa(ll x){
	return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}
void uni(ll a, ll b){
	fa[findFa(a)] = findFa(b);
}

bool kruskal(){
	sort(t+1, t+1+tc, mycmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	ll c = 0;
	for(int i = 1; i <= tc; i++){
		ll u = t[i].u, v = t[i].v, w=t[i].w;
		if(findFa(u)!=findFa(v)){
			c++;
			uni(u, v);
			ans = max(ans, w);
		}
		if(c == n-1) break;
	}
	return c == n-1;
}

int main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < m; i++){
		ll x, y, w;
		scanf("%lld%lld%lld", &x, &y, &w);
		t[++tc].u = x;
		t[tc].v = y;
		t[tc].w = w;
	}
	if(kruskal())
		printf("%lld\n", ans);
	else printf("-1\n");
	return 0;
}
