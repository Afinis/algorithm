#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5;
ll n, k, T, c = 1e5, ans = N;

struct node{
	ll v, i;
}a[N];

int main(){
	scanf("%lld%lld%lld", &n, &k, &T);	
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].v);
		a[i].i = i+1;
	}
	if(n < k){
		printf("-1\n");
		return 0;
	}
	if(n > 1e4){
		c = 1000;
	}
	while(c--){
		random_shuffle(a, a+n);
		double me = 0, sig = 0;
		ll t = 0;
		for(int i = 0; i < k; i++){
			me += a[i].v;
			t = max(a[i].i, t);
		}
		me /= (double)k;
		for(int i = 0; i < k; i++){
			sig += (a[i].v-me)*(a[i].v-me);
		}
		sig /= (double)k;
		if(sig < T && ans > t){
			ans = t;
		}
	}
	if(ans == N){
		printf("-1\n");
	}else{
		printf("%lld\n", ans);
	}
	return 0;
}
