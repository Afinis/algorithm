#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10;
ll a[N], fa[N+10], n;

ll find(ll x){
	ll t = x;
	while(x != fa[x]){
		x = fa[x];
	}
	while(t != fa[t]){
		ll oldT = t;
		t = fa[t];
		fa[oldT] = x;
	}
	return x;
} 

int main(){
	scanf("%lld", &n);
	for(ll i = 0; i < N; i++){
		fa[i] = i;
	}
	for(ll i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		a[i] = find(a[i]);
		fa[a[i]] = a[i]+1;
	}
	for(ll i = 0; i < n; i++){
		if(i) printf(" ");
		printf("%lld", a[i]);
	}
	return 0;
}
