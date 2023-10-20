#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p, e[100000+5];
int main(){
	scanf("%lld%lld", &n, &p);
	for(int i = 0; i < n; i++) scanf("%lld", &e[i]);
	sort(e, e+n);
	int r = 1;
	for(int i = 0; i < n; i++){
		int j = upper_bound(e+i+1, e+n, (ll)e[i]*p) - e;
		r = max(r, j-i);
	}
	printf("%d", r);
	return 0;
}
