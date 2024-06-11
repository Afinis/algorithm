#include<bits/stdc++.h>
using namespace std;
const int N = 5e6;
int n, q, tr[N];
struct node{
	int x, d;
};

void bfs(int x, int y, int z){
	vector<int > inq(n+10, 0);
	queue<node> q;
	q.push(node{x, 0});
	inq[x] = 1;
	
	while(!q.empty()){
		node u = q.front(); q.pop();
		tr[u.x] = z;
		
		if(u.d == y) continue;
		int ls = u.x*2, rs = u.x*2+1, p = u.x/2;
		if(p && !inq[p]){
			q.push(node{p, u.d+1});
			inq[p] = 1;
		}
		if(ls <= n && !inq[ls]){
			q.push(node{ls, u.d+1});
			inq[ls] = 1;
		}
		if(rs <= n && !inq[rs]){
			q.push(node{rs, u.d+1});
			inq[rs] = 1;
		}
	}
}


int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < q; i++){
		int op, x, y, z;
		scanf("%d", &op);
		if(op==1){
			scanf("%d%d%d", &x, &y, &z);
			bfs(x, y, z);
		}else{
			scanf("%d", &x);
			printf("%d\n", tr[x]);
		}
	}
	return 0;
}
