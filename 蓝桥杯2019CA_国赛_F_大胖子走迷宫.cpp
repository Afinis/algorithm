#include<bits/stdc++.h>
using namespace std;
int n, k, inq[305][305], ans=1e7;
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
string g[305];
struct node{
	int x, y, k, fat;
};
bool check_bound(int nx, int ny){
	return !(nx<0 || nx>=n || ny<0 || ny>=n || inq[nx][ny] || g[nx][ny]=='*');
}
bool check(int x, int y, int fat){
	for(int i = x-fat/2; i <= x+fat/2; i++)
	for(int j = y-fat/2; j <= y+fat/2; j++)
		if(i<0||i>=n || j<0||j>=n || g[i][j]=='*')
			return false;		
	return true;
}

int Fat(int x){
	if(x < k){
		return 5;
	}else if(x < 2*k){
		return 3;
	}else return 1;
}

void bfs(){
	queue<node> q;
	node st;
	st.x = 2, st.y = 2, st.k = 0, st.fat=5;
	q.push(st);
	inq[st.x][st.y] = 1;
	while(!q.empty()){
		node t = q.front(); q.pop();
		if(t.x==n-3 && t.y == n-3){
			ans = t.k;
			break;
		}
		for(int i = 0; i < 4; i++){
			int nx = t.x+X[i], ny = t.y+Y[i], nk = t.k+1;
			if(!check_bound(nx, ny)) continue;
			if(check(nx, ny, t.fat)){
				node e; e.x=nx, e.y=ny;
				e.k=nk, e.fat = Fat(nk);
				inq[nx][ny] = 1;
				q.push(e);
			}
		}
		if(t.fat!=1){
			t.k++;
			t.fat = Fat(t.k);
			q.push(t);
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>g[i];
	}
	bfs();
	cout<<ans<<endl;
	return 0;
}
