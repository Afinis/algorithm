#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000+10;
struct node{
	ll a, e;
}s[N];

bool cmp(node a, node b){
	return a.a+a.e < b.a+b.e; 
}

ll n, sum[N], ans;

int main(){
	scanf("%lld", &n);
	for(ll i =0; i < n; i++){
		ll si, ai, ei;
		scanf("%lld%lld%lld", &si, &ai, &ei);
		s[i].a = si+ai, s[i].e = ei;
	} 
	sort(s, s+n, cmp);
	for(ll i =0; i < n; i++){
		if(i) sum[i] = sum[i-1] + s[i-1].a + s[i-1].e;
		ans += sum[i] + s[i].a;
	}
	printf("%lld\n", ans);
	return 0;
}
