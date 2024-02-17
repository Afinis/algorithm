#include<bits/stdc++.h>
using namespace std;
int n, m, a[105][15], inq[100000], dp[100000], en;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);	
	queue<int> q;
	q.push(pow(2, n)-1);
	inq[int(pow(2, n)-1)] = 1;
	while(!q.empty()){
		int sta = q.front(); q.pop();
		int p = dp[sta];
		for(int i = 0; i < m; i++){
			int ne = sta;
			for(int j = 0; j < n; j++){
				if(a[i][j]==1 && sta&(1<<j)){
					ne = ne&(~(1<<j));
				}else if(a[i][j]==-1 && !(sta&(1<<j)) ){
					ne = ne|(1<<j);
				}
			}
			if(ne == 0){
				dp[ne] = p+1;
				en = 1;
				printf("%d", dp[0]);
				return 0;
			}
			if(!inq[ne] ){
				inq[ne] = 1;
				q.push(ne);
				dp[ne] = p+1;
			}
		}
	}
	printf("-1");
	return 0;
}
