#include<bits/stdc++.h>
using namespace std;

// dp[i] 表示以数字i结尾的最长接龙序列的长度 
int dp[100000+10], ans;

int main(){
	int n; cin>>n; 
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		dp[s[s.size()-1]-'0'] = max(dp[s[0]-'0']+1, dp[s[s.size()-1]-'0']);
	}
	for(int i = 0; i < 10; i++) ans = max(ans, dp[i]);
	cout<<n-ans<<endl;
	return 0;
}
