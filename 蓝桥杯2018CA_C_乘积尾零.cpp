#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e4;
struct bign{
	ll a[M], len;
	bign(){
		memset(a, 0, sizeof a);
		len = 0;
	}
};

bign mul(bign x, ll y){
	bign c;
	ll pro = 0;
	for(ll i = 0; i < x.len; i++){
		ll t = x.a[i] * y + pro;
		c.a[c.len++] = t%10;
		pro = t/10;
	}
	while(pro){
		c.a[c.len++] = pro%10;
		pro /= 10;
	}
	return c;
}

int main(){
	bign x;
	x.a[0] = 1; x.len=1;
	for(ll i = 0; i < 100; i++){
	    ll t;
		cin>>t;
		x = mul(x, t);
	}
	ll ans = 0;
	for(ll i = 0; i < x.len; i++){
		if(x.a[i]==0){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
