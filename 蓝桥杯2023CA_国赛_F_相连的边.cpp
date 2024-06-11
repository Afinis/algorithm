#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
ll n, ans, ec;
struct node{
	ll v, e;
};
bool cmp(node a, node b){
	return a.e > b.e;
}

vector<node> t[N];

struct edge{
	ll e, u, v;
}e[N];
bool cmp2(edge a, edge b){
	return a.e > b.e;
}

int main(){
	scanf("%lld", &n);
	for(ll i = 1; i < n; i++){
		ll u = i+1, v, w;
		scanf("%lld%lld", &v, &w);
		t[u].push_back(node{v, w});
		t[v].push_back(node{u, w});
		e[ec] = edge{w, u, v};
		ec++;
	}
	for(ll i = 1; i <= n; i++){
		sort(t[i].begin(), t[i].end(), cmp);
	}
	sort(e, e+ec, cmp2);
	for(ll i = 0; i < ec; i++){
		ll u = e[i].u, v = e[i].v, w = e[i].e;
		ll sum = w;
		for(ll l = 0; l < t[u].size(); l++){
			if(t[u][l].v == v) continue;
			sum += t[u][l].e;
			break;
		}
		for(ll l = 0; l < t[v].size(); l++){
			if(t[v][l].v == u) continue;
			sum += t[v][l].e;
			break;
		}
		ans = max(ans, sum);
	}
	for(ll i = 1; i <= n; i++){
		if(t[i].size() >= 3){
			ans = max(ans, t[i][0].e+t[i][1].e+t[i][2].e);
		}
	}
	printf("%lld", ans);
	return 0;
}
