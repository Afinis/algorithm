#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
#define ls p<<1
#define rs p<<1|1
ll n, Y[N]; //存储y坐标 
struct line{
	ll y1, y2, x;
	ll tag;
}L[N];
bool cmp(line a, line b){
	return a.x < b.x;
}

struct tre{
	ll l, r;
	ll cnt, len;
}t[N*8];

void build(ll l, ll r, ll p){
	t[p] = {l, r, 0, 0};
	if(l== r) return;
	ll mi = l+r>>1;
	build(l, mi, ls);
	build(mi+1, r, rs);
}

void pushUp(ll p){
	if(t[p].cnt) t[p].len = Y[t[p].r+1] - Y[t[p].l];
	else t[p].len = t[ls].len + t[rs].len;
}

void update(ll l, ll r, ll tag, ll p){
	if(l <= t[p].l && t[p].r <= r){
		t[p].cnt += tag;
		pushUp(p); // 开8倍数组的原因 
		return;
	}
	ll mi = t[p].l+t[p].r>>1;
	if(l <= mi) update(l, r, tag, ls);
	if(mi < r)  update(l, r, tag, rs);
	pushUp(p);
}

int main(){
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		ll x1, x2, y1, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		L[i] = {y1, y2, x1, 1};
		L[n+i] = {y1, y2, x2, -1};
		Y[i] = y1, Y[n+i] = y2;
	} 
	n*=2;
	sort(L, L+n, cmp);
	// 坐标离散化 
	sort(Y, Y+n);
	ll ly = unique(Y, Y+n) - Y;
	// 右端点偏移映射[t[i].l, t[i].r]对应区间[Y[t[i].l], Y[t[i].r+1]] 
	build(0, ly-1-1, 1);
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		ll l = lower_bound(Y, Y+ly, L[i].y1) - Y;
		ll r = lower_bound(Y, Y+ly, L[i].y2) - Y;
		update(l, r-1, L[i].tag, 1);
		ans += t[1].len*(L[i+1].x - L[i].x);
	}
	printf("%lld\n", ans);
	return 0;
}
