#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n, m, k, inq[N][N][13];
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
string g[N];

struct node{
	int x, y, k, d;
};

bool bfs(){
	queue<node> q;
	node st;
	st.x=0, st.y=0, st.k=1, st.d=0;
	q.push(st);
	while(!q.empty()){
		node t = q.front();
		q.pop();
		if(t.x==n-1&&t.y==m-1){
			cout<<t.d<<endl;
			return 1;
		}
		for(int i = 0; i < 4; i++){
			int nx = X[i]+t.x, ny = Y[i]+t.y, nk, nd=t.d+1;
			if(nx<0||nx>=n||ny<0||ny>=m) continue;
			if(g[nx][ny]==g[t.x][t.y]){
				nk = t.k+1;
			}else{
				if(t.k!=k) continue;
				else nk = 1;
			}
			if(nk>k || inq[nx][ny][nk]) continue;
			inq[nx][ny][nk]=1;
			node ne; ne.x=nx, ne.y=ny, ne.k=nk, ne.d=nd;
			q.push(ne);
		}
	}
	return 0;
}

int main(){
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		cin>>g[i];
	}
	if(!bfs()) cout<<-1<<endl;
	return 0;
}
