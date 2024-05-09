#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t;
	cin>>t;
	for(ll i = 0; i < t; i++){
		ll L, R;
		cin>>L>>R;
		if(R-2*L<0){
			cout<<0<<endl;
			continue;
		}
		ll ans = (R-2*L+1)*(R-L+1) - R*(R-2*L+1)/2;
		cout<<ans<<endl;
	}
	return 0;
}
