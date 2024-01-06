#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1000+5;
ll hi[M], lo[M], dp[M][M], w[M];

int main(){
	int n, x; scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &lo[i], &hi[i], &w[i]);
	}
	for(int i = 0; i <= x; i++){
		for(int j = 1; j <= n; j++){
			if(i - w[j] >= 0){
				dp[i][j] = dp[i-w[j]][j-1] + hi[j];
			}
			dp[i][j] = max(dp[i][j-1] + lo[j], dp[i][j]);
		}
	}
	printf("%lld", dp[x][n]*5);
	return 0;
}
