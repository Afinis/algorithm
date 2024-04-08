#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 60, INF = 5e8, F=-2;
ll  n = 30, m = 50, vis[N][N]; 
string g[N];
ll X[5] = {1, 0, 0, -1};
ll Y[5] = {0, -1, 1, 0};
map<pair<ll, ll>, pair<ll, ll>> pre;

void ouT(ll x, ll y){
	if(x==0&&y==0) return;
	ll px=pre[{x, y}].first, py=pre[{x, y}].second;
	ouT(px, py);
	ll dx = x-px, dy = y-py;
	if(dx==0&&dy==1){
		cout<<"R";
	}else if(dx==0&&dy==-1){
		cout<<"L";
	}else if(dx==1&&dy==0){
		cout<<"D";
	}else if(dx==-1&&dy==0){
		cout<<"U";
	}
}

struct node{
	ll x, y, d;
};
ll inq[100][100];

bool check(ll x, ll y){
	if(0<=x&&x<n && 0<=y&&y<m && !inq[x][y] && g[x][y]!='1'){
		return true;
	}
	return false;
}

ll bfs(){
	queue<node> q;
	node e; e.x = 0, e.y = 0, e.d=0;
	q.push(e);
	while(!q.empty()){
		node t = q.front(); q.pop();		
		for(ll i = 0; i < 4; i++){
			ll nx = t.x+X[i], ny = t.y+Y[i];
			if(check(nx, ny)){
				node ne;
				ne.x=nx, ne.y=ny, ne.d=t.d+1;
				inq[nx][ny] = 1;
				q.push(ne);
				pre[{nx, ny}] = {t.x, t.y};
				if(nx == n-1 && ny == m-1)
					return ne.d;		
			}
		}
	}
	return -1;
}

int main(){	
	for(ll i = 0; i < n; i++)
		cin>>g[i];
	bfs();	
	ouT(n-1, m-1);
	return 0;
}
