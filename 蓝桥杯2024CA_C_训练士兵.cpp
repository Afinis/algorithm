#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
ll n, s, ans, sum, p;
struct node{
	ll p, c;
}v[N];

bool cmp(node a, node b){
	return a.c < b.c;
}

int main(){	
	scanf("%lld%lld", &n, &s);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &v[i].p, &v[i].c);
	}
	sort(v, v+n, cmp);
	for(int i = 0; i < n; i++){
		p += v[i].c * v[i].p;
		sum += v[i].p;
	}
	if(sum < s){
		ans = p;
	}else
		for(int i = 0; i < n; i++){
			ll t = s*v[i].c + p - sum*v[i].c;
			if(ans == 0 || t < ans){
				ans = t;
			}
			sum -= v[i].p;
			p -= v[i].p*v[i].c;
		}
	printf("%lld\n", ans);
	return 0;
}
