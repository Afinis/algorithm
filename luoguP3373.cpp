#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e5+10;
ll n, q, m, a[M];

struct node{
	ll v, l, r, add, mul = 1;
}tr[M*4];

void pushUp(ll p){
	tr[p].v = (tr[p*2].v%m + tr[p*2+1].v%m)%m;
}

void pushDown(ll p){
	if(tr[p].mul != 1 || tr[p].add){
		ll mi = (tr[p].l + tr[p].r)/2;
		tr[p*2].v = ((tr[p*2].v%m*tr[p].mul%m)%m+tr[p].add%m*(mi-tr[p].l+1))%m;
		tr[p*2+1].v = ((tr[p*2+1].v%m*tr[p].mul%m)%m+tr[p].add%m*(tr[p].r-mi))%m;
	
		tr[p*2].mul = (tr[p*2].mul%m*tr[p].mul%m)%m;
		tr[p*2+1].mul = (tr[p*2+1].mul%m*tr[p].mul%m)%m;
		tr[p*2].add = (tr[p*2].add*tr[p].mul+tr[p].add)%m;
		tr[p*2+1].add = (tr[p*2+1].add*tr[p].mul+tr[p].add)%m;
		tr[p].mul=1;
		tr[p].add=0;
	}
}

void build(ll l, ll r, ll p){
	tr[p].l = l, tr[p].r = r;
	tr[p].mul = 1, tr[p].add = 0;
	if(l==r){
		tr[p].v = a[l];
		return;
	}
	ll mi = (l+r)/2;
	build(l, mi, p*2);
	build(mi+1, r, p*2+1);
	pushUp(p);
}

void update(ll l, ll r, ll v, ll typ,ll p){
	ll lt = tr[p].l, rt = tr[p].r;
	if(l<=tr[p].l && tr[p].r<=r){
		if(typ==1){ // ³Ë 
			tr[p].v = (tr[p].v%m*v%m)%m;
			tr[p].mul = (tr[p].mul%m*v%m)%m;
			tr[p].add = (tr[p].add%m*v%m)%m;
		}else{ // ¼Ó 
			tr[p].v = (tr[p].v+v%m*(tr[p].r-tr[p].l+1)%m)%m;
			tr[p].add = (tr[p].add%m+v%m)%m;
		}
		return;
	}
	pushDown(p);
	ll mi = (tr[p].l + tr[p].r)/2;
	if(l <= mi){
		update(l, r, v, typ, p*2);
	}
	if(mi < r){
		update(l, r, v, typ, p*2+1);
	}
	pushUp(p);
}

ll query(ll l, ll r, ll p){
	if(l<=tr[p].l && tr[p].r<=r){
		return tr[p].v%m;
	}
	pushDown(p);
	ll sum = 0, mi = (tr[p].l + tr[p].r)/2;
	if(l <= mi){
		sum += query(l, r, p*2)%m;
	}
	if(mi < r){
		sum += query(l, r, p*2+1)%m;
	} 
	pushUp(p);
	return sum%m;
}

int main(){
	scanf("%d%d%d", &n,&q,&m);
	for(ll i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	build(1, n, 1);
	for(ll i = 1; i <= q; i++){
		ll typ;
		scanf("%lld", &typ);
		if(typ==1){
			ll x, y, k;
			scanf("%lld%lld%lld", &x,&y,&k);
			update(x, y, k, typ, 1);
		}else if(typ==2){
			ll x, y, k;
			scanf("%lld%lld%lld", &x,&y,&k);
			update(x, y, k, typ, 1);
		}else{
			ll x, y;
			scanf("%lld%lld", &x,&y);
			ll t = query(x, y, 1);
			printf("%lld\n", t);
		}
	}
	return 0;
}
