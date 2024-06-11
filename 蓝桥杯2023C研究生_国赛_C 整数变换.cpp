#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;

ll cal(ll x){
	ll t = 0;
	while(x){
		t += x%10;
		x /= 10;
	}
	return t;
}

int main(){
	cin>>n;
	while(n){
		ans++;
		n = n-cal(n);
	}	
	cout<<ans<<endl;
	return 0;
}
