#include<bits/stdc++.h>
using namespace std;
int g[100][100], ans, vis[10];

void dfs(int s, int i){
	vis[i]=1;
	for(int j = 1; j <= 7; j++)
		if(g[i][j]&&(s&(1<<(j-1)))&&vis[j]==0)
			dfs(s, j);
}

bool check(int s){
	fill(vis, vis+10, 0);
	int c = 0;
	for(int i = 0; i < 7; i++)
		if(s&(1<<i)&&vis[i+1]==0){
			c++;
			dfs(s, i+1);
		}
	return c==1;
}

int main(){
	// a1, b2, c3, d4, e5, f6, g7
	g[1][2]=g[1][6]=1; 
	g[2][1]=g[2][7]=g[2][3]=1;
	g[3][2]=g[3][4]=g[3][7]=1;
	g[4][3]=g[4][5]=1;
	g[5][4]=g[5][7]=g[5][6]=1;
	g[6][1]=g[6][7]=g[6][5]=1;
	g[7][2]=g[7][3]=g[7][6]=g[7][5]=1;
	
	for(int s = 1; s < (1<<7); s++)
		if(check(s)) ans++;
	cout<<ans<<endl;
	return 0;
}
