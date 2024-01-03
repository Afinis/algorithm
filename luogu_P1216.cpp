#include<bits/stdc++.h>
using namespace std;
int dp[1000+5][1000+5], e[1000+5][1000+5];
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++) scanf("%d", &e[i][j]);
		
	for(int i = n-1; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			i == n-1 ? dp[i][j] = e[i][j] : dp[i][j] = max(dp[i+1][j] + e[i][j], dp[i+1][j+1] + e[i][j]);
		
	printf("%d", dp[0][0]);
}
