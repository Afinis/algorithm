#include<bits/stdc++.h>
using namespace std;
const int M = 19650827;
int n, a[1005], dp[1005][1005][2];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		dp[i][i][0] = 1;
	}
	for(int i = 1; i < n; i++){
		for(int j = i; j < n; j++){
			int lo = j-i;
			if(a[lo] < a[lo+1]){
				dp[lo][j][0] += dp[lo+1][j][0];
				dp[lo][j][0] %= M;
			}
			if(a[lo] < a[j]){
				dp[lo][j][0] += dp[lo+1][j][1];
				dp[lo][j][0] %= M;
			}
			if(a[j] > a[lo]){
				dp[lo][j][1] += dp[lo][j-1][0];
				dp[lo][j][1] %= M;
			}
			if(a[j] > a[j-1]){
				dp[lo][j][1] += dp[lo][j-1][1];
				dp[lo][j][1] %= M;
			}
		}
	}
	cout<<(dp[0][n-1][0] + dp[0][n-1][1])%M<<endl;
	return 0;
}
