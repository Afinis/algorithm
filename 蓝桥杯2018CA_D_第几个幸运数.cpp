#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 59084709587505, ans; 
ll a[] = {3, 5, 7};
void dfs(ll i, ll pref){
	// j >= 0 必须得有，否则会出现a[-1] 
	for(ll j = 2; a[j] >= pref && j >= 0; j--){
		if(i < n/a[j]){
			dfs(i*a[j], a[j]);
			ans++;
		}
	}
}

int main(){
	dfs(1, 3);
	cout<<ans+1<<endl;
	return 0;
}
