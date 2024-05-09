#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w, h, ans;
map<ll, ll> mp;

ll defac(ll x){
	ll sq = sqrt(x), xx = x;
	for(ll i = 2; i <= sq; i++){
		if(xx % i == 0){
			mp[i]++;
		}
		if(x % i == 0){
			while(x%i==0){
				x /= i;
			}
		}
	}
	if(x!=1){
		mp[x]++;
	}
	return x;
}

int main(){
	cin>>w>>h;
	ll sqw = sqrt(w), sqh = sqrt(h);
	defac(w);
	defac(h);
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->second >= 2){
			ans = w/it->first * h/it->first;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
