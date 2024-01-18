#include<bits/stdc++.h>
using namespace std;

int n, m, a[105], dp[105][105], M = 1000000+7;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		dp[0][i] = 1;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			for(int c = 0; c <= a[j]; c++){
				if(i - c >= 0){
					dp[i][j] += dp[i-c][j-1];
					dp[i][j] %= M;
				}
			}
		}
	}
	printf("%d", dp[m][n]);
}
