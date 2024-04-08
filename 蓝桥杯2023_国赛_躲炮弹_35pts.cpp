#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e6;
ll l, r, n, p[N], ans=1e8;
unordered_map<ll, ll> mp;
void init(){
	for(ll i = l; i <= r; i++){
		for(ll j = i; j < N; j+= i){
			p[j]=1;
		}
	}
} 

int main(){
	scanf("%lld%lld%lld", &n, &l, &r);
	if(n<l) printf("0\n");
	init();
	for(ll i = n; i < N; i++){
		if(p[i]==0){
			ans = min(i-n, ans);
			break;
		}
	}
	for(ll i = n; i ; i--){
		if(p[i]==0){
			ans = min(n-i, ans);
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
