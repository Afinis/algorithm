#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, g[N][N], d[N][N], t[N][N];
int X[] = {0, 1};
int Y[] = {1, 0};

struct node{
	int x, y, l, tag;
};

void bfs(){
	queue<node> q;
	q.push(node{0, 0, 0, 0});
	d[0][0] = 0;
	
	while(!q.empty()){
		node u = q.front();
		q.pop();
		
		for(int i = 0; i < 2; i++){
			int nx = u.x + X[i], ny = u.y + Y[i], nl, tag=0;
			if(!(nx<n && ny<n)) continue;
			if(i==0){
				if(g[u.x][u.y] > g[nx][ny]){
					if(u.tag){
						nl = u.l;
						tag = u.tag;
					}else{
						nl = u.l+1;
						tag = 1;				
					}
				}else{
					nl = u.l+1;
					tag = 0;
				}
			}else{
				tag = 0;
				nl = u.l+1;
			}
			
			if(nl < d[nx][ny]){
				q.push(node{nx, ny, nl, tag});
				d[nx][ny] = nl;
				t[nx][ny] = tag;
			}else if(nl == d[nx][ny] && tag && t[nx][ny]==0){
				q.push(node{nx, ny, nl, tag});
				t[nx][ny] = 1;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	fill(d[0], d[0]+N*N, (int)1e8);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &g[i][j]);
		}
	}
	bfs();
/*	
	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", d[n-1][n-1]);
	return 0;
}
