#include<bits/stdc++.h>
using namespace std;

int g[105][105], dp[105][105], mx;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int r, c;

int dfs(int x, int y){
	if(dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nex = x + X[i], ney = y + Y[i];
		if(0<=nex&&nex<r && 0<=ney&&ney<c && g[x][y] > g[nex][ney]){
			dfs(nex, ney);
			dp[x][y] = max(dp[nex][ney] + 1, dp[x][y]);
		}
	}
	return dp[x][y];
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			scanf("%d", &g[i][j]);
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			dfs(i, j);
			mx = max(mx, dp[i][j]);
		}
	}	
	printf("%d", mx);
	return 0;
} 
