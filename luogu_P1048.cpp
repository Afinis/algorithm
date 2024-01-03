#include<bits/stdc++.h>
using namespace std;

int t, m, dp[1000+5][100+5], w[100+5], v[100+5];

int main(){
	scanf("%d%d", &t, &m);
	for(int i = 1; i <= m; i++ )
		scanf("%d%d", &w[i], &v[i]);
		
	for(int i = 1; i <= t; i++){
		for(int j = 1; j <= m; j++){
			if(i-w[j] >= 0)
				dp[i][j] = dp[i-w[j]][j-1] + v[j];
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}
	printf("%d", dp[t][m]);
	return 0;
}
