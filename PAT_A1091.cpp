#include<bits/stdc++.h>
using namespace std;

int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};
struct node{
	int x, y, z;
};

int m, n, l, t, r,  g[65][1300][129], vis[65][1300][129];

bool check(int x, int y, int z){
	if(0<=x && x<m && 0<=y && y<n && 0<=z && z<l && g[z][x][y]==1 && vis[z][x][y]==0)
		return true;
	return false;
}

int bfs(int x, int y, int z){
	int c = 0;
	queue<node> q;
	node e; e.x = x; e.y=y; e.z=z;
	q.push(e);
	vis[z][x][y]=1;
	while(!q.empty()){
		node t = q.front(); q.pop();
		c++;
		for(int i = 0; i < 6; i++){
			int xn = t.x + X[i], yn = t.y + Y[i], zn = t.z + Z[i];
			if(check(xn, yn, zn)){
				node e;
				e.x = xn; e.y = yn; e.z=zn;
				q.push(e);
				vis[zn][xn][yn]=1;	
			}
		}
	}
	return c;
}

int main(){
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int z = 0; z < l; z++){
		for(int x = 0; x < m; x++){
			for(int y = 0; y < n; y++){
				scanf("%d", &g[z][x][y]);
			}
		}		
	}
	for(int z = 0; z < l; z++){
		for(int x = 0; x < m; x++){
			for(int y = 0; y < n; y++){
				if(vis[z][x][y] == 0 && g[z][x][y] == 1){
					int c = bfs(x, y, z);
					if(c >= t){
						r += c;
					}
				}

			}
		}		
	}
	printf("%d", r);
	return 0;
}
