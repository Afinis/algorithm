#include<bits/stdc++.h>
using namespace std;

int dp[2000+5][2000+5];

int main(){
	string a, b; cin>>a>>b;
	int la = a.size(), lb = b.size();
	for(int j = 1; j <= lb; j++) dp[0][j] = j;
	for(int i = 1; i <= la; i++) dp[i][0] = i;
	for(int i = 1; i <= la; i++){
		for(int j = 1; j <= lb; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				int t = min(dp[i-1][j]+1, dp[i][j-1]+1);
				t = min(t, dp[i-1][j-1] + 1);
				dp[i][j] = t;
			}
		}
	}	
	printf("%d\n", dp[la][lb]);
	return 0;
}
