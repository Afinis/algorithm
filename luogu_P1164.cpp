#include<bits/stdc++.h>
using namespace std;
int n, m, a[100+5], dp[10000+5][100+5];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int j = 0; j <= n; j++)
		dp[0][j] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(i-a[j] >= 0)
				dp[i][j] = dp[i-a[j]][j-1] + dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1];
		}
	}
	printf("%d", dp[m][n]);
	return 0;
}
