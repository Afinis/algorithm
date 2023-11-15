#include<bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int g[350][350], inq[350][350]; 
struct node{
	int x, y, t;
};

bool check(int x, int y, int t){
	if(0<=x && 0<= y && inq[x][y] == 0 && (g[x][y] == -1 || t < g[x][y])){
		for(int i = 0;i < 4; i++){
			int nx = x + X[i], ny = y + Y[i];
			if(nx >= 0 && ny >= 0 && g[nx][ny] != -1 && t >= g[nx][ny] ) return false;
		}
		return true;
	}
	return false;
}

int main(){
	memset(g, -1, sizeof(g));
	int m; scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		if(g[x][y]==-1 || g[x][y] > t) g[x][y] = t;
	}
	queue<node> q;
	node e, r;
	e.x = 0; e.y = 0; e.t = 0;
	q.push(e);
	int en = 0;
	while(!q.empty()){
		node f = q.front(); q.pop();
		if(g[f.x][f.y+1]==-1 && (f.y==0 || g[f.x][f.y-1]==-1) && g[f.x+1][f.y]==-1
			&& (f.x==0 || g[f.x-1][f.y]==-1) && g[f.x][f.y]==-1){
			r = f;
			en = 1;
			break;
		}		
		for(int i = 0;i < 4; i++){
			int nx = f.x + X[i], ny = f.y + Y[i], nt = f.t + 1;
			if(check(nx, ny, nt)){
				node t;
				t.x = nx;
				t.y = ny;
				t.t = nt;
				q.push(t);
				inq[nx][ny] = 1;
			}
		}
	}
	en ? printf("%d\n", r.t) : printf("-1\n");
	return 0;
}
