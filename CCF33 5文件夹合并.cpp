#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
ll n, m, fa[N], w[N];
unordered_map<ll, ll> mp[N];

ll dp = 0;
void dfs(ll x){
	dp++;
	if(x==1){
		return;
	}
	dfs(fa[x]);
} 

int main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 2; i <= n; i++){
		ll t;
		scanf("%lld", &t);
		fa[i] = t;
		mp[t][i]++;
	} 
	for(int i = 1; i <= n; i++){
		ll t;
		scanf("%lld", &t);
		w[i] = t;
	}
	for(int i = 1; i <= m; i++){
		ll x, op;
		scanf("%lld%lld", &op, &x);
		if(op==1){
			vector<ll> son, del;
			for(auto it = mp[x].begin(); it != mp[x].end(); it++){
				ll u = it->first;
				w[x] += w[u];
				w[u] = 0;
				for(auto iq = mp[u].begin(); iq != mp[u].end(); iq++){
					ll v = iq->first;
					son.push_back(v);
				}
				
				del.push_back(u);
			}
			for(int k = 0; k < son.size(); k++){
				mp[x][son[k]]++;
				fa[son[k]] = x;
			}
			for(int k = 0; k < del.size(); k++){
				mp[x].erase(del[k]);
			}
			printf("%d %lld\n", mp[x].size(), w[x]);
		}else{
			dp = 0;
			dfs(x);
			printf("%lld\n", dp);
		}
		
	}
	
	
	return 0;
}
