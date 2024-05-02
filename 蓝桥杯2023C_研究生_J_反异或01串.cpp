#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, T, ans;
string t; 

ll rev(ll x){
	ll r = 0;
	for(ll i = 0; i < n; i++){
		if(x&(1<<i)){
			r |= (1<<(n-i-1));
		}
	}
	return r;
}

ll cal(ll x){
	ll r = 0;
	for(ll i = 0; i < n; i++){
		if(x&(1<<i)){
			r++;
		}
	}
	return r;
}

int main(){
	cin>>t; n = t.size();
	for(ll i = 0; i < n; i++){
		if(t[i]=='1'){
			T |= (1<<i);
			ans++;
		}
	}
	if(ans <= 1 || n >= 64){
		cout<<ans<<endl;
		return 0;
	}
	ll m = 1<<n;
	for(ll i = 0; i < m; i++){
		if(T== (i ^ rev(i))){
			ans = min(ans, cal(i));
		}
	}
	cout<<ans<<endl;
	return 0;
}
