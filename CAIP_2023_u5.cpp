#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int p[N], a[N], b[N], dp[N][5], ma,mb;

int main(){
	map<pair<int, int>, int> mm;
	mm[{0,0}] = mm[{1,1}] = 2;
	mm[{0,1}] = 3;
	mm[{1,0}] = 1;
	
	int t;
	scanf("%d", &t);
	for(int xx = 0; xx < t; xx++){
		int n;
		scanf("%d", &n);
		ma = mb = 0;
		memset(p,0,sizeof(p)); memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			scanf("%d", &b[i]);
		}
		for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
						
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				int lo = N;
				for(int k = 1; k <= j; k++){
					if(lo > dp[i-1][k]) lo = dp[i-1][k];
				}
				dp[i][j] = lo;	
				if(j!=mm[{a[p[i]], b[p[i]]}])
					dp[i][j] += 1;
			}
		}
		int r = dp[n][1];
		for(int j = 2; j <= 3; j++)
			if(r > dp[n][j]) r = dp[n][j];
		
		printf("%d\n", r);
	}
	return 0;
}
