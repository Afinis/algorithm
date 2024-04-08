#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5*1e5+10, INF = 1e16;
struct node{
	ll l, r, v;
}t[4*M];
ll n, k, a[M];
void pushUp(ll p){
	t[p].v = min(t[p*2].v, t[p*2+1].v);
}

void build(ll p, ll l, ll r){
	t[p].l=l, t[p].r=r;
	if(t[p].l==t[p].r){
		t[p].v = a[l];
		return;
	}
	ll mi = (l+r)/2;
	build(p*2, l, mi);
	build(p*2+1, mi+1, r);
	pushUp(p);
}

ll minV;
ll remov(ll p){
	if(t[p].l==t[p].r){	
		minV = t[p].v;
		t[p].v = INF;
		a[t[p].l] = INF;
		return t[p].l;
	}
	ll rk = 0;
	if(t[p*2].v <= t[p*2+1].v){
		rk = remov(p*2);
	}else{
		rk = remov(p*2+1);
	}
	pushUp(p);
	return rk;
}

// [1, i]从i向1，第一个小于INF的位置
ll queryLV(ll i, ll p){
	if(t[p].l==t[p].r){
		return t[p].l;
	}
	ll mi = t[p].l + t[p].r >> 1, ans=0;
	if(mi+1<=i && t[p*2+1].v < INF){
		ans = queryLV(i, p*2+1);
	}
	if(ans) return ans;
	if(1<=mi && t[p*2].v < INF){
		ans = queryLV(i, p*2);
	}
	return ans;
}

// [i, n]从i向n，第一个小于INF的位置
ll queryRV(ll i, ll p){ 
	if(t[p].l==t[p].r){
		return t[p].l;
	}
	ll mi = t[p].l + t[p].r >> 1, ans=0;
	if(i<=mi && t[p*2].v<INF){
		ans = queryRV(i, p*2);
	}
	if(ans) return ans;
	if(n >= mi+1 && t[p*2+1].v<INF){
		ans = queryRV(i, p*2+1);
	}
	return ans;
}

void addV(ll i, ll p){
	if(t[p].l==t[p].r){
		t[p].v += minV;
		a[t[p].l] += minV;
		return;
	}
	ll mi = t[p].l + t[p].r >> 1;
	if(i <= mi){
		addV(i, p*2);
	}
	if(i >= mi+1){
		addV(i, p*2+1);
	}
	pushUp(p);
}

int main(){
	scanf("%lld%lld", &n, &k);
	for(ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for(ll i = 0; i < k; i++){
		ll rk = remov(1);
		if(rk-1>=1){
			ll loc = queryLV(rk-1, 1);
			if(loc)
				addV(loc, 1);
		}
		if(rk+1<=n){
			ll loc = queryRV(rk+1, 1);
			if(loc)
				addV(loc, 1);
		}
	}
	for(ll i = 1; i <= n; i++){
		if(a[i] < INF){
			printf("%lld ", a[i]);
		}
	}
	return 0;
}
