#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct fractor{
	ll x, c;
}fac[11];
ll c;
int main(){
	ll n; scanf("%lld", &n);
	ll sqr = sqrt(n), oldn = n;
	for(ll i = 2; i < sqr; i++)
		if(n % i == 0){
			while(n % i == 0){
				fac[c].c++;
				n /= i;
			}
			fac[c++].x = i;
		}
	if(n != 1){
		fac[c].x = n;
		fac[c++].c++;
	}
	printf("%lld=", oldn);
	for(ll i = 0; i < c; i++){
		if(i!=0) printf("*");
		fac[i].c==1 ? printf("%lld", fac[i].x) : printf("%lld^%lld", fac[i].x, fac[i].c);
	}
	if(oldn==1) printf("1");
	return 0;
}
