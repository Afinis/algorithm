#include<bits/stdc++.h>
using namespace std;

int n, m;
struct node{
	int to;
	int last;
}e[500];
int head[20], c;
long long dp[1 << 20][20], ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[++c].to = --v;
		e[c].last = head[--u];
		head[u] = c;
		
		e[++c].to = u;
		e[c].last = head[v];
		head[v] = c;
	}
	for(int i = 0; i < n; i++)
		dp[1<<i][i] = 1;
	
	for(int sta = 0; sta < (1<<n); sta++){
	for(int u = 0; u < n; u++){
		if(dp[sta][u]){				
		for(int v = head[u]; v; v = e[v].last){
			if(!(sta & ((1 << (e[v].to+1))-1)) ) continue;
			if( !((1 << e[v].to) & sta) )
				dp[sta|(1 << e[v].to)][e[v].to] += dp[sta][u];
			else if((sta&(1 << e[v].to)) && !(sta&((1 << e[v].to)-1)) ){
				ans += dp[sta][u];
			}	
		}	
		}
	}
	}	
	printf("%lld\n", (ans-m)/2);
	return 0;
}
