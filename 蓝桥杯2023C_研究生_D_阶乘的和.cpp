#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
map<ll, ll> mp; 
ll n; 
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		int t; cin>>t;
		mp[t]++;
	}
	// map会自动按照从小到大排序 
	for(auto it = mp.begin(); it != mp.end(); it++){
		ll num = it->second, a = it->first;
		if(num%(a+1)==0){
			mp[a+1] += num/(a+1);
		}else{
			cout<<a<<endl;
			return 0;
		}
	}
	return 0;
}
