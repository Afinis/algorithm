#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10, M = 5003;
ll dp[N][2], a[N], n;

int main(){
	cin>>n;
	if(n==0){
		cout<<1<<endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	n = unique(a+1, a+1+n) - (a+1);
	fill(dp[0], dp[0]+N*2, 1);
	dp[1][1] = a[1];
	for(int i = 2; i <= n; i++){
		dp[i][1] = (dp[i-1][1]+dp[i-1][0])%M*a[i]%M;
		dp[i][0] = (dp[i-1][1]+dp[i-1][0])%M;
	}
	cout<<(dp[n][1] + dp[n][0])%M<<endl;
	return 0;
}
