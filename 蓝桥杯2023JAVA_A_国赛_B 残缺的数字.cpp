#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20], c[20], z[20], dp[20];
ll mp[] = {126, 48, 127-2-16, 127-6, 3+48, 127-4-32, 95, 64+32+16, 127, 127-4};

bool check(ll x, ll y){
	
	for(ll i = 0; i < 7; i++){
		if(x & (1<<i)){
			if(!(y & (1<<i))){
				return false;
			}
		}
	}
	return true;
}

void pre(ll id){
	if(id == 1){
		int ppp = 1;
	}
	for(ll i = 1; i <= 9; i++){
		if(check(a[id], mp[i])){
			c[id]++;
		}
	}
	if(check(a[id], mp[0])){
		z[id]++;
	}
}

int dec(int x){
	int m = 1, r = 0;
	while(x){
		if(x%10){
			r += (x%10)*m;
		}
		m<<=1;
		x/=10;
	}
	return r;
}

int main(){
/*	a[0] = 127-32;
	pre(0);
	a[1] = 127-12;
	pre(1);*/
	for(ll i = 17; i >= 0; i--){
		cin>>a[i];
		a[i] = dec(a[i]);
		pre(i);
	}
	dp[0] = c[0] + z[0];
	dp[1] = c[1] * dp[0];
	ll ans = 1;
	for(ll i = 0; i <= 17; i++){
		ans *= (c[i]+z[i]);
	}
	cout<<ans<<endl; // 254016000
	for(ll i = 2; i <= 17; i++){
		dp[i] = c[i]*(dp[i-1] + z[i]*dp[i-2]);
	}
	cout<<dp[17]<<endl; //931392000
	return 0;
}
