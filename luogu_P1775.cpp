#include<bits/stdc++.h>
using namespace std;
int n, a[305], dp[305][305], v[305][305];
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		v[i][i] = a[i];
	}
	for(int i = 1; i < n; i++){
		dp[i-1][i] = a[i-1] + a[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			v[j][i] = v[j][i-1] + a[i];
		}
	}
	for(int i = 2; i < n; i++){
		for(int j = i; j < n; j++){
			for(int p = 0; j-i+p+1 <= j; p++){
				int t= dp[j-i][j-i+p]+dp[j-i+p+1][j]+v[j-i][j-i+p]+v[j-i+p+1][j];
				dp[j-i][j] = dp[j-i][j] == 0 ? t : min(dp[j-i][j], t);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
