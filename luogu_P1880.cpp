#include<bits/stdc++.h>
using namespace std;
int n, e[205], a[205][205], dp[205][205], g[205][205];
int main(){
	cin>>n;
	for(int i = 0; i < n; i++) cin>>e[i];
	copy(e, e+n, e+n);
	for(int i = 0; i < 2*n; i++){
		a[i][i] = e[i];	
		for(int j = i-1; j >= 0; j--){
			a[j][i] = a[j+1][i] + e[j];
//			printf("a[%d][%d]=%d\n", j, i, a[j][i]);
		}	
	}
	for(int i = 1; i < 2*n; i++){
		for(int j = i; j < 2*n; j++){
			int lo = j-i;
			for(int p = 0; lo+p+1 <= j; p++){	
				if(dp[lo][j] == 0)
					dp[lo][j] = dp[lo][lo+p]+dp[lo+p+1][j]+a[lo][lo+p]+a[lo+p+1][j];
				else
					dp[lo][j] = min(dp[lo][j], dp[lo][lo+p]+dp[lo+p+1][j]+a[lo][lo+p]+a[lo+p+1][j]);
				if(g[lo][j] == 0)
					g[lo][j] = g[lo][lo+p]+g[lo+p+1][j]+a[lo][lo+p]+a[lo+p+1][j];
				else
					g[lo][j] = max(g[lo][j], g[lo][lo+p]+g[lo+p+1][j]+a[lo][lo+p]+a[lo+p+1][j]);	
			}
	//		printf("dp[%d][%d]=%d\n", j-i, j, dp[lo][j]);
		}
	}
	int r = dp[0][n-1], r2 = g[0][n-1];
	for(int i = 1; i <= n; i++){
		r = min(r, dp[i][i+n-1]);
		r2 = max(r2, g[i][i+n-1]);
	}
	cout<<r<<endl<<r2<<endl;;
	return 0;
}
