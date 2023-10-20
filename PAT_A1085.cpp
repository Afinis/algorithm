#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p, e[100000+5];
int main(){
	scanf("%lld%lld", &n, &p);
	for(int i = 0; i < n; i++) scanf("%lld", &e[i]);
	sort(e, e+n);
	int lo = 0, hi = n, mi=0;
	while(hi > lo){
		mi = (hi + lo)>>1;
		int en = 0;
		for(int i = 0; i + mi < n; i++){
			if(e[i + mi] <= e[i]*p){
				en = 1;
				break;
			}
		}
		if(en) lo = mi+1;
		else hi = mi;
	}
	printf("%d", mi+1);
	return 0;
}
