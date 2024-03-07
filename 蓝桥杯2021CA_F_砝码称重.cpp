#include<bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, w[100+5], dp[105][M+1], ans;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>w[i];
	dp[0][w[0]] = 1;
	dp[0][0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= M; j++){
			if(dp[i-1][j]){
				dp[i][j+w[i]] = 1;
				dp[i][j] = 1;
				if(j-w[i]>=0)
					dp[i][j-w[i]] = 1;
				else
					dp[i][w[i]-j] = 1;	
			}
		}
	}
	for(int i = 1; i <= M; i++)
		ans += dp[n-1][i];
	cout<<ans<<endl;
	return 0;
}
