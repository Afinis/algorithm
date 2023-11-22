#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int n, g[N][N], vis[N][N], f[N][N] , c;
int closed(int x, int y){
    int r = 1;
	vis[x][y] = 1;
	if(x == 0 || x== n-1 || y == 0 || y== n-1)
		return 0;
	for(int i = 0; i < 4; i++){
		int nx = x + X[i], ny = y + Y[i];
		if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1)
			return 0;
		if(g[nx][ny]==0 && vis[nx][ny] == 0)
            r = min(r, closed(nx, ny));
	}
    return r;
}

void fil(int x, int y){
	f[x][y] = 1;
	g[x][y] = 2;
	for(int i = 0; i < 4; i++){
		int nx = x + X[i], ny = y + Y[i];
		if(0<nx && nx<n-1 && 0<ny && ny<n-1 && f[nx][ny] == 0 && g[nx][ny]!=1)
			fil(nx, ny);
	}
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>g[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			memset(vis, 0, sizeof(vis));
			if(g[i][j]==0 && closed(i, j))
				fil(i, j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j != 0) cout<<" ";
			cout<<g[i][j];
		}
			cout<<endl;
	}
	return 0;
}
