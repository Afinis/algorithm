#include<bits/stdc++.h>
using namespace std;
int n, G[10][10], dp[10][10][10][10];
int main(){
	scanf("%d", &n);
	while(true){
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		if(t == 0 && x==0 && y==0) break;
		G[x][y] = t;
	}
	for(int a = 1; a <= n; a++)
	for(int b = 1; b <= n; b++)
	for(int x = 1; x <= n; x++)
	for(int y = 1; y <= n; y++){
		int t = max(dp[a-1][b][x-1][y], dp[a][b-1][x-1][y]);
		t = max(t, dp[a-1][b][x][y-1] );
		t = max(t, dp[a][b-1][x][y-1] );
		dp[a][b][x][y] = t + G[a][b];
		if(a != x && b != y)
			dp[a][b][x][y] += G[x][y];	
	}
	printf("%d\n", dp[n][n][n][n]);
	return 0;
}
