#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
#define ls p*2
#define rs p*2+1
ll n, m, q;

struct node{
	ll l, r;
	ll v, tag;
}t[N*4];

void build(ll l, ll r, ll p){
	t[p].l = l, t[p].r = r, t[p].v=0, t[p].tag=0;
	if(l==r){
		return;
	}
	ll mi = l+r>>1;
	build(l, mi, ls);
	build(mi+1, r, rs);
}

void ass(ll l, ll r, ll s, ll p){
	if(t[p].l == t[p].r){
		t[p].v = s;
		t[p].tag = 1;
		return;
	}
	ll mi = t[p].l + t[p].r;
	if(l <= mi){
		ass(l , r, s-())
	}
}

int main(){
	scanf("%lld%lld%lld", &n, &m, &q);
	build(1, n, 1);
	for(int i = 0; i < m; i++){
		ll l, r, s;
		scanf("%lld%lld%lld", &l, &r, &s);
	}
	
	
	return 0;
}
