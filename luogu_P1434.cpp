#include<bits/stdc++.h>
using namespace std;
int g[105][105], dp[105][105], mx;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
struct node{	
	int x, y;
	node(int x, int y){
		this->x = x, this->y = y;
	}
};
struct cmpl{
	bool operator()(node a,node b){
        return g[a.x][a.y] > g[b.x][b.y];
    }
};
priority_queue <node, vector<node>, cmpl > q;

int main(){
	int r, c; scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d", &g[i][j]);
			q.push(node(i, j));
		}
	}
	while(!q.empty()){
		node t = q.top(); q.pop();
		for(int i = 0; i < 4; i++){
			int nex = t.x + X[i], ney = t.y + Y[i];
			if(0<=nex&&nex<r&&0<=ney&&ney<c && g[t.x][t.y] > g[nex][ney]){
				dp[t.x][t.y] = max(dp[t.x][t.y], dp[nex][ney] + 1);
			}	
		}
		mx = max(mx, dp[t.x][t.y]);
	} 
	printf("%d", mx+1);
	return 0;
}
