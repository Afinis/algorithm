#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e5, n = 12;
unordered_map<ll, int> mp;
int main(){
	for(ll i = 1; i <= M; i++){
		for(ll j = i; j <= M; j++){
			ll r = i*i+j*j;
			mp[r]++;
			if(mp[r]==n){
				cout<<r<<endl;
				return 0;
			}
		}
	}		
	return 0;
}
