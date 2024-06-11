#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll d = 2000;
ll n, L, R;

bool check(ll x){
	ll sq = sqrt(x);
	for(ll i = 1; i <= sq; i++){
		if(x % i == 0){
			if(L <= i && i <= R) return false;
			if(L <= x/i && x/i <= R) return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>L>>R;
	if(n > R){
		for(ll i = 0; i < d; i++){
			if(check(n+i) || check(n-i)){
				cout<<i<<endl;
				break;
			}
		}
	}else if(n < L){
		cout<<0<<endl;
	}else{
		ll ans = n-(L-1);
		for(ll i = R+1; i < R+d; i++){
			if(check(i)){
				cout<<min(ans, i-n)<<endl;
				break;
			}
		}
	}
	return 0;
}
