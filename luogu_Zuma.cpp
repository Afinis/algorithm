#include<bits/stdc++.h>
using namespace std;

int n, a[505], dp[505][505];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		dp[i][i] = 1;
	}
	for(int i = 1; i < n; i++){
		for(int j = i; j < n; j++){
			dp[j-i][j] = 100000;
			if(a[j-i]==a[j]){
				if(i==1) dp[j-i][j] = 1;
				else dp[j-i][j] = dp[j-i+1][j-1];
			}
			for(int p = 0; j-i+p+1 <= j; p++){
				dp[j-i][j] = min(dp[j-i][j], dp[j-i][j-i+p]+dp[j-i+p+1][j] );
			}
	//		printf("dp[%d][%d]=%d\n", j-i, j,dp[j-i][j] );
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}
