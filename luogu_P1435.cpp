#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
string a;
int main(){
	cin>>a;
	for(int i = 1; i < a.size(); i++){
		for(int j = i; j < a.size(); j++){
			dp[j-i][j] = min(dp[j-i+1][j]+1, dp[j-i][j-1]+1 );
			if(a[j-i] == a[j]){
				dp[j-i][j] = min(dp[j-i][j], dp[j-i+1][j-1]);
			}
		}
	}
	cout<<dp[0][a.size()-1];
	return 0;
}
