#include<bits/stdc++.h>
using namespace std;
typedef unsigned  long long ll;
const ll N = 1e12; 
ll sum[(ll)3e7];

ll findn(ll n){
	ll lo = 1, hi = 1e7;
	while(lo < hi){
		ll mi = (lo+hi)/2;
		ll l = (mi)*(mi-1)/2+1;
		if(n < l)
			hi = mi;
		else lo = mi+1;
	}
	return lo-1;
}

int main(){
	ll n = findn(N)+100;
	for(ll i = 1; i <= n; i++){
		sum[i] = sum[i-1] + (1+i)*i/2;
	}
	ll q;
	scanf("%lld", &q);
	for(ll i = 0; i < q; i++){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ll nl = findn(l), nr = findn(r), ans=-1;
		
		if(nl==nr){
			ll t = nl*(nl-1)/2;
			l -= t, r-= t;
			if((l+r)%2==0) ans = (l+r)/2*(r-l+1);
			else ans = (r-l+1)/2*(l+r);
			printf("%lld\n", ans);
		}else{
			ll p1 = sum[nr-1] - sum[nl];
			ll t = nl; //区间右边界 
			l -= nl*(nl-1)/2;
			
			ll p2;
			if((l+t)%2==0) 
				p2 = (l+t)/2*(t-l+1);
			else
				p2 = (t-l+1)/2*(l+t);
			
			t = 1; //区间左边界 
			r -= nr*(nr-1)/2;
			
			ll p3;
			if((t+r)%2==0){
				p3 = (t+r)/2*(r-t+1); 
			}else{
				p3 = (r-t+1)/2*(t+r); 
			}
			ans = p1+p2+p3;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
