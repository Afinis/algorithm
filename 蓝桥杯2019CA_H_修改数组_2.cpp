#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+10;
ll a[N], n, c[N];

ll lowbit(ll x){
	return x & -x;
}

ll query(ll x){
	ll sum=0;
	while(x>0){
		sum+=c[x];
		x -= lowbit(x);
	}
	return sum;
}

void add(ll x){
	while(x<=N){
		c[x]++;
		x += lowbit(x);
	}
}

int main(){
	scanf("%lld", &n);
	for(ll i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		ll lo = a[i], hi = N;
		while(lo < hi){
			ll mi = lo+hi>>1;
			if(query(mi)-query(lo-1) == mi-lo+1){
				lo = mi+1;
			}else{
				hi = mi;
			}
		}
		add(hi);
		a[i] = hi;
	}
	for(ll i = 0; i < n; i++){
		if(i) printf(" ");
		printf("%lld", a[i]);
	}
	return 0;
}
