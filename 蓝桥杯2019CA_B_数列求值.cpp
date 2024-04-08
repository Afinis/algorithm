#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 20190324+10, n = 20190324, M=10000;
ll dp[N]; 

int main(){
	dp[1] = dp[2] = dp[3] = 1;
	for(ll i = 4; i <= n; i++){
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%M;
		if(i<=10) cout<<dp[i]<<endl; 
	}
	cout<<dp[n]<<endl;
	return 0;
}
