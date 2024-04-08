#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, r, N=2023, ans=-1;

void dfs(ll i, ll j){
	if(i==n+1 && j==m+1){
		if(r%N==0){
			ans = max(ans, r);
		}
		return;
	}
	if(i <= n){
		r = r*10 + 2;
		dfs(i+1, j);
		r /= 10;
	}
	if(j <= m){
		r = r*10 + 3;
		dfs(i, j+1);
		r /= 10;
	}
}

int main(){
	cin>>n>>m;
	if(n+m<20)
		dfs(1, 1);
	cout<<ans<<endl;
	return 0;
}
