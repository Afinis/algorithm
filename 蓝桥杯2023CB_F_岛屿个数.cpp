#include<bits/stdc++.h>
using namespace std;
const int M = 60;
int X[] = {1, -1, 0, 0, 1, -1, -1, 1};
int Y[] = {0, 0, 1, -1, 1, -1, 1, -1};
int m, n, vis[M][M], vc, g[M][M], numC;
struct island{
	int x, y, vc;
}la[M*M];
int lc;

bool check_bound(int x, int y){
	if(x < 1 || x > m || y < 1 || y > n || g[x][y]==0){
		return false;
	}
	return true;
}

void dfs(int x, int y, int px, int py){
	vis[x][y]=vc;
	for(int i = 0; i < 4; i++){
		int nx = x + X[i], ny = y + Y[i];
		if(check_bound(nx, ny)){
			if(vis[nx][ny]==0){			
				dfs(nx, ny, x, y);
			}	
		}
	}	
}

struct node{
	int x, y;
};
int inq[M][M], inc;
bool bfs(int x, int y){
	queue<node> q;
	node st; st.x = x, st.y = y; 
	q.push(st);
	while(!q.empty()){
		node now = q.front(); q.pop();
		for(int i = 0; i < 8; i++){
			int nx = now.x + X[i], ny = now.y + Y[i];
			if(nx < 1 || nx > m || ny < 1 || ny > n){
				return true;
			}
			if(g[nx][ny] == 0 && inq[nx][ny]!=inc){
				node t;
				t.x=nx, t.y=ny;
				q.push(t);
				inq[nx][ny] = inc;
			}
		}
	}
	return false;
}

int main(){
	int T; cin>>T;
	for(int i = 0; i < T; i++){
		vc = numC = lc = inc = 0;
		memset(vis, 0, sizeof vis);
		memset(inq, 0, sizeof inq);
		memset(g, 0, sizeof g);
		cin>>m>>n;
		for(int j = 1; j <= m; j++){
			string s; cin>>s;		
			for(int k = 1; k <= s.size(); k++){
				g[j][k] = s[k-1]-'0';
			}
		}
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				if(g[j][k]==1 && vis[j][k]==0){
					vc++;
					dfs(j, k, 0, 0);
					la[lc].x = j;
					la[lc].y = k;
					la[lc].vc = vc;
					lc++;
				}	
				
			}
		}
		for(int j = 0; j < lc; j++){
			inc++;
			if(!bfs(la[j].x, la[j].y)){
				numC++;
			}
		}
		cout<<lc-numC<<endl;
	}
	return 0;
}
