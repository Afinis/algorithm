#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10, INF = -1e16;
ll n, q, a[N];

struct node{
	ll l, r, v;
	ll upd, add;
}t[4*N];

void pushUp(ll p){
	t[p].v = max(t[p*2].v, t[p*2+1].v);
}

void build(ll l, ll r, ll p){
	t[p].l = l, t[p].r = r, t[p].upd = INF, t[p].add = 0;
	if(l==r){
		t[p].v = a[l];
		return;
	}
	ll mi = l+r>>1;
	build(l, mi, p*2);
	build(mi+1, r, p*2+1);
	pushUp(p);
}

void pushDown(ll p){
	if(t[p].upd != INF){
		t[p*2].v = t[p].upd + t[p].add;
		t[p*2+1].v = t[p].upd + t[p].add;
		t[p*2].add = t[p*2+1].add = t[p].add;
		t[p*2].upd = t[p*2+1].upd = t[p].upd;
	}else{
		t[p*2].v += t[p].add;
		t[p*2+1].v += t[p].add;
		t[p*2].add += t[p].add;
		t[p*2+1].add += t[p].add;
	}
	t[p].add = 0;
	t[p].upd = INF;
}

void update(ll l, ll r, ll x, ll typ, ll p){
	if(l <= t[p].l && t[p].r <= r){
		if(typ==1){ // 修改值 
			t[p].v = x;
			t[p].add = 0;
			t[p].upd = x;
		}else{ // 加值 
			t[p].v += x;
			t[p].add += x;
		}
		return;
	}
	pushDown(p);
	ll mi = t[p].l + t[p].r>>1;
	if(l <= mi)
		update(l, r, x, typ, p*2);
	if(mi+1 <= r)
		update(l, r, x, typ, p*2+1);	
	pushUp(p);
}

ll Find(ll l, ll r, ll p){
	if(l <= t[p].l && t[p].r <= r)
		return t[p].v;
	pushDown(p);
	ll mi = t[p].l + t[p].r>>1, ans = INF;
	if(l <= mi)
		ans = max(ans, Find(l, r, p*2));
	if(mi+1 <= r)
		ans = max(ans, Find(l, r, p*2+1));
	return ans;
}

int main(){
	scanf("%lld%lld", &n, &q);	
	for(ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	build(1, n, 1);
	for(ll i = 0; i < q; i++){
		ll op, l, r, x;
		scanf("%lld", &op);
		if(op==3){
			scanf("%lld%lld", &l, &r);
			ll ans = Find(l, r, 1); 
			printf("%lld\n", ans);
		}else{
			scanf("%lld%lld%lld", &l, &r, &x);
			update(l, r, x, op, 1);
		}
	}
	return 0;
}
