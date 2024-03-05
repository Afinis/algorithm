#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100000+5;
struct node{
	ll to, last;
	ll s;
}e[2*MAX];
ll head[MAX], ce;
// vis同时也表示连通域 
ll n, m, q, vis[MAX], cv, s[MAX];

void add(ll u, ll v, ll s){
	ce++;
	e[ce].to=v;
	e[ce].last=head[u];
	e[ce].s = s;
	head[u] = ce;
}

void dfs(ll i){
	if(!vis[i]) vis[i] = ++cv;
	for(ll j = head[i]; j; j=e[j].last){
		ll v = e[j].to;
		if(vis[v]) continue;
		vis[v] = vis[i];
		s[v] = s[i] + e[j].s; 
		dfs(v);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &q);	
	for(int i = 0; i < m; i++){
		ll l, r, s;
		scanf("%lld%lld%lld", &l, &r, &s);
		l--;
		add(l, r, s);
		add(r, l, -s);
	}
	for(int i = 0; i < q; i++){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		l--;
		if(!vis[l]) dfs(l);
		if(vis[l]==vis[r])
			printf("%lld\n", s[r]-s[l]);
		else
			printf("UNKNOWN\n");
	}
	return 0;
}
