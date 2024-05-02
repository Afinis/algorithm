#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005], ans = 1e6;
string s, t; 
int main(){
	cin>>s>>t;
	fill(dp[0], dp[0]+1000*1000, 100000);
	for(int i = 0; i <= s.size(); i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
			}else{
				dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]);
			}
		}
	}
	for(int i = t.size(); i <= s.size(); i++){
		ans = min(ans, dp[i][t.size()]);
	}
	cout<<ans<<endl;
	return 0;
}
