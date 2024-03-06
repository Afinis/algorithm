#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n = 2021041820210418;
ll cf = 0, a[1000];
struct fac{
	ll p, cnt;
}f[1000];

void defac(ll x){
	ll sq = sqrt(x);
	for(ll i = 2; i <= sq; i++){
		if(x%i==0){
			f[cf].p=i;
			while(x%i==0){
				x /= i;
				f[cf].cnt++;
			}
			cf++;
		}
	}
	if(x!=1){
		f[cf].p=x;
		f[cf].cnt++;
		cf++;
	}
}

int main(){
	defac(n);
	for(ll i = 0; i < cf; i++)
		for(ll j = 0; j <= f[i].cnt; j++)
			for(ll k = 0; j+k <= f[i].cnt; k++)
				a[i]++;	
	ll ans = 1;
	for(ll i = 0; i < cf; i++)
		ans *= a[i];
	cout<<ans<<endl;
	return 0;
}
