#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
unordered_map<ll, int> mp;
int c[11];
ll r;
bool check(ll x, ll a, ll b){
	memset(c, 0, sizeof(c));
	while(a){
		c[a%10]++;
		a/=10;
	}
	while(b){
		c[b%10]++;
		b/=10;
	}
	while(x){
		c[x%10]--;
		x/=10;
	}
	for(int i = 0; i < 10; i++){
		if(c[i]!=0) return false;
	}
	return true;
}


int main(){
	cout<<check(180225, 225, 801)<<endl;
	cout<<check(126, 21, 6)<<endl;
	for(ll i = 1; i <= N; i++){
		for(ll j = i; j*i <= N; j++){
			ll t = i*j;			
			if(check(t, i, j)){
				mp[t]++; 
				r++;	
			}
		}
	}	
	cout<<mp.size()<<endl; // 590
	cout<<r<<endl;
	return 0;
}
