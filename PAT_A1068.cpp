#include<bits/stdc++.h>
using namespace std;
const int N = 10000, M = 100;
int v[N+5], dp[N+5][M+5], ch[N+5][M+5];

bool mycmp(int a, int b){
	return a>b;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i] );
	sort(v+1, v+n+1, mycmp);
	dp[0][0]=1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j-v[i] >= 0)
				if(dp[i-1][j-v[i]]) dp[i][j] = ch[i][j] = 1;	
			dp[i][j] = dp[i][j] || dp[i-1][j];
		}
	}
	int bo = 1;
	for(int i = n; i >= 1; i--){
		if(ch[i][m]){
			bo=0;
			int k = i;
			int j = m;
			int f = 0;
			while(j){
				if(ch[k][j]){
					printf("%s%d", f ? " " : "", v[k]);
                    f = 1;
                    j -= v[k];
				}
				k--;
			}
			break;
		}
	}
	if(bo) printf("No Solution");	
	return 0;
}
