#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, s, a[50], mi, ans = 0;
//map<pair<ll, ll>, ll> su;
unordered_map<ll , ll> ma[50];
ll fac(ll x){
	ll r = 1;
	for(ll i = x; i > 1; i--){
		if(r > s/i) return -1;
		r *= i;
	}
	return r;
}
ll calc(ll ck, ll sum){
	ll r = 0;
	for(ll i = 0; i <= ck; i++){
//		r += su[{sum, i}];
		r += ma[i][sum];
	}
	return r;
}
void dfs_l(ll i, ll ck, ll sum){
	if( i >= mi){
//        su[{sum, ck}]++;
        ma[ck][sum]++;
        return;
    }
	dfs_l(i+1, ck, sum);
	if(sum + a[i] <= s){
		dfs_l(i+1, ck, sum+a[i]);
		ll f;
		if(ck < k && (f = fac(a[i])) != -1 && sum + f <= s)
			dfs_l(i+1, ck+1, sum+f);
	}
}

void dfs_r(ll i, ll ck, ll sum){
	if(i >= n){
        ans += calc(k - ck, s - sum);
        return;
    }
	dfs_r(i+1, ck, sum);
	if(sum + a[i] <= s){
		dfs_r(i+1, ck, sum+a[i]);
		ll f;
		if(ck < k && (f = fac(a[i])) != -1 && sum + f <= s)
			dfs_r(i+1, ck+1, sum+f);
	}
}
int main(){
	cin>>n>>k>>s;
	for(int i = 0; i < n; i++) cin>>a[i];
	mi = n/2;
	dfs_l(0, 0, 0);
	dfs_r(mi, 0, 0);
	cout<<ans<<endl;
	return 0;
}
