#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+10;
ll n, m, pre[N];
char s[N];

struct node{
	ll l, r, minV=2*N, maxV=-2*N, add=0, rev=0;
} t[4*N];

void pushUp(ll p){
	t[p].maxV = max(t[p*2].maxV, t[p*2+1].maxV);
	t[p].minV = min(t[p*2].minV, t[p*2+1].minV);
}

void tag_Rev(ll p){
	swap(t[p].maxV, t[p].minV);
	t[p].maxV = -t[p].maxV;
	t[p].minV = -t[p].minV;
	t[p].rev ^= 1;
	t[p].add *= -1;
}

void tag_add(ll p, ll v){
	t[p].add += v;
	t[p].maxV += v;
	t[p].minV += v;
}

void pushDown(ll p){
	if(t[p].rev){
		tag_Rev(p*2);
		tag_Rev(p*2+1);
		t[p].rev = 0;
	}
	if(t[p].add){
		tag_add(p*2, t[p].add);
		tag_add(p*2+1, t[p].add);
		t[p].add = 0;
	}
}

void build(ll l, ll r, ll p){
	t[p].l = l, t[p].r = r, t[p].rev=0;
	if(l == r){
		t[p].minV = t[p].maxV = pre[l];
		return;
	}
	ll mi = (l+r)/2;
	build(l, mi, p*2);
	build(mi+1, r, p*2+1);
	pushUp(p);
}

ll query(ll x, ll p){
	if(!x) return 0;
	if(t[p].l == t[p].r){
		return t[p].maxV;
	}
	pushDown(p);
	ll mi = (t[p].l + t[p].r)/2;
	if(x <= mi){
		return query(x, p*2);
	}else{
		return query(x, p*2+1);
	}
}

// 查找 [l, n] 第一个小于值 v 的位置 r，没有则返回 n+1
ll bs1(ll l, ll v, ll p){
	if(t[p].l == t[p].r){
		return t[p].r;
	}
	pushDown(p);
	ll mi = (t[p].l + t[p].r)/2, r = n+1;
	if(l <= mi && t[p*2].minV < v){
		r = bs1(l, v, p*2);
	}
	if(r!=n+1){
		return r;
	}
	if(t[p*2+1].minV < v){
		r = bs1(l, v, p*2+1);
	}
	return r;
}

// 查找 [1, r] 上第一个小于 v 的位置 l
ll bs2(ll r, ll v, ll p){
	if(t[p].l == t[p].r){
		return t[p].r;
	}
	pushDown(p);
	ll mi = (t[p].l + t[p].r)/2, l = -1;
	if(mi < r && t[p*2+1].minV < v){
		l = bs2(r, v, p*2+1);
	}
	if(l>0){
		return l;
	}
	if(t[p*2].minV < v){
		l = bs2(r, v, p*2);
	}
	return l;
}

ll findRight(ll l){
	ll v = l==1 ? 0 : query(l-1, 1);
	ll ans = bs2(bs1(l, v, 1)-1, v+1, 1);
	return ans>l ? ans : 0;
}

void add(ll l, ll r, ll v, ll p){
	if(l <= t[p].l && t[p].r <= r){
		tag_add(p, v);
		return;
	}
	pushDown(p);
	ll mi = (t[p].l+t[p].r)/2;
	if(l <= mi){
		add(l, r, v, p*2);
	}
	if(mi < r){
		add(l, r, v, p*2+1);
	}
	pushUp(p);
}

void rever(ll l, ll r, ll p){
	if(l <= t[p].l && t[p].r <= r){
		tag_Rev(p);
		return;
	}
	pushDown(p);
	ll mi = (t[p].l+t[p].r)/2;
	if(l <= mi){
		rever(l, r, p*2);
	}
	if(mi < r)
		rever(l, r, p*2+1);
	pushUp(p);
}

void update(ll r, ll p){
	if(!r) return;
	if(r < n){
		ll tsum = query(r, 1);
		add(r+1, n, -2*tsum, p);
	}
	rever(1, r, p);
}

int main(){
	scanf("%lld%lld", &n, &m);
	scanf("%s", s+1);
	for(ll i = 1; i <= n; i++){
		pre[i] += pre[i-1] + (s[i]=='(' ? 1 : -1);
	}
	build(1, n, 1);
	for(ll i = 0; i < m; i++){
		ll cho, x, y;
		scanf("%lld", &cho);
		if(cho == 1){
			scanf("%lld%lld", &x, &y);
			update(y, 1);
			if(x!=1) update(x-1, 1);
		}else{
			scanf("%lld", &x);
			ll r = findRight(x);
			printf("%lld\n", r);
		}
	}
	return 0;
}
