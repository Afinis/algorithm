#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, m, g[N][N], inq[N][N], c;

bool check(int x, int y){
	if(0 <= x && x < n && 0 <= y && y < m && inq[x][y] == 0 && g[x][y]==1)
		return true;
	return false;
}

void bfs(int x, int y){
	queue<pair<int , int> > q;
	q.push({x, y});
	while(!q.empty()){
		auto e = q.front(); q.pop();
		for(int i = 0; i < 8; i++){
			int nx = e.first + X[i], ny = e.second + Y[i];
			if(check(nx, ny)){
				inq[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			char t;
			cin>>t;
			g[i][j] = (t == 'W') ;
		}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			if(g[i][j]==1 && inq[i][j] == 0){
				c++;
				bfs(i, j);
			}
	}
	cout<<c<<endl;
	return 0;
}
