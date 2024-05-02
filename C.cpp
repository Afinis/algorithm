#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200000+10], sum, ans;

int main(){
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sum = a[n];
	for(ll i = n-1; i >= 1; i--){
		ans += a[i] * sum;
		sum += a[i]; 
	}
	printf("%lld", ans);
	return 0;
}
