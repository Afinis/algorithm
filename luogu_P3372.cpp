#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e5+10;
ll n, m, a[M], d[4*M], b[4*M];

void build(ll l, ll r, ll p){
	// 对 [l,r] 区间建立线段树,当前根节点为 p
	if(l==r){
		d[p] = a[l];
		return;
	}
	ll mi = l + ((r-l)>>1);
	// 递归对左右区间建树
	build(l, mi, p*2);
	build(mi+1, r, p*2+1);
	d[p] = d[p*2] + d[p*2+1];
}

ll getSum(ll lo, ll hi, ll l, ll r, ll p){
	// [lo, hi]为查询区间, [l, r]为当前节点包含的区间, p为当前节点
	if(lo<=l && r<=hi) 
		return d[p];
	ll sum = 0, mi = l+((r-l)>>1);
	
	// 标记下传 
	if(b[p]){
		d[p*2] += b[p]*(mi-l+1);
		b[p*2] += b[p];
		d[p*2+1] += b[p]*(r-mi);
		b[p*2+1] += b[p];
		b[p] = 0;
	}
	
	if(lo <= mi)
		sum += getSum(lo, hi, l, mi, p*2);	
	if(mi < hi)
		sum += getSum(lo, hi, mi+1, r, p*2+1);
	
	return sum;
} 

void update(ll lo, ll hi, ll c, ll l, ll r, ll p){
	if(lo<=l && r<=hi){
		d[p] += (r-l+1)*c;
		b[p] += c;
		return;
	}
	ll mi = l+((r-l)>>1);
	
	// 标记下传 
	if(b[p] && l!=r){
		d[p*2] += (mi-l+1)*b[p];
		b[p*2] += b[p];
		d[p*2+1] += (r-mi)*b[p];
		b[p*2+1] += b[p];
		b[p] = 0;
	}
	
	if(lo <= mi){
		update(lo, hi, c, l, mi, p*2);
	}
	if(mi < hi){
		update(lo, hi, c, mi+1, r, p*2+1);
	}
	d[p] = d[p*2] + d[p*2+1];
}

int main(){
	scanf("%lld%lld", &n, &m);
	for(ll i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	build(1, n, 1);
	for(ll i = 0; i < m; i++){
		ll typ;
		scanf("%lld", &typ);
		if(typ==1){
			ll x, y, k;
			scanf("%lld%lld%lld", &x, &y, &k);
			update(x, y, k, 1, n, 1);
		}else{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			ll t = getSum(x, y, 1, n, 1);
			printf("%lld\n", t);
		}
	}
	return 0;
}
