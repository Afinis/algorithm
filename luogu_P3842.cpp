#include<bits/stdc++.h>
using namespace std;
const int M = 2*10000 + 5;
int n, dp[M][5], g[M][2];

int main(){
	scanf("%d", &n);	
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &g[i][0], &g[i][1]);
	}
	dp[1][0] = (g[1][1] - 1) + (g[1][1] - g[1][0]);
	dp[1][1] = (g[1][1] - 1);
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				int jp = g[i-1][j], kp = g[i][k], l = g[i][0], r = g[i][1];
				if( jp < l){
					if(dp[i][k] == 0){
						dp[i][k] = dp[i-1][j] + r-jp + r-kp;
					}else dp[i][k] = min(dp[i][k], dp[i-1][j] + r-jp + r-kp);
				}else if(jp > r){
					if(dp[i][k] == 0){
						dp[i][k] = dp[i-1][j] + jp-l + kp-l;
					}else dp[i][k] = min(dp[i][k], dp[i-1][j] + jp-l + kp-l);
				}else{
					if(k == 0){
						if(dp[i][k] == 0){
							dp[i][k] = dp[i-1][j] + r-l + r-jp;
						}else dp[i][k] = min(dp[i][k], dp[i-1][j] + r-l + r-jp );
					}else{
						if(dp[i][k] == 0){
							dp[i][k] = dp[i-1][j] + r-l + jp-l;
						}else dp[i][k] = min(dp[i][k], dp[i-1][j] + r-l + jp-l);
					}
				}
			}
		}
	}
	
	int r = min(dp[n][0] + n-g[n][0], dp[n][1] + n-g[n][1]);
	printf("%d", r+n-1);
	return 0;
}
