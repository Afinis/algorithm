#include<bits/stdc++.h>
using namespace std;
const int N = 2020;
int g[N][N], n, mx, my; 
long long od, ev;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int l, b, r, t;
		scanf("%d%d%d%d", &l, &b, &r, &t);
		l++, b++;
		g[l][b]++;
		g[r+1][t+1]++;
		g[l][t+1]--;
		g[r+1][b]--;
		mx = max(r, mx);
		my = max(t, my);
	}
	for(int i = 1; i <= mx; i++){
		for(int j = 1; j <= my; j++){
			g[i][j] += g[i][j-1];
			g[i][j] += g[i-1][j];
			g[i][j] -= g[i-1][j-1];
			if(g[i][j]==0) continue;
			if(g[i][j]%2==0){
				ev++;
			}else{
				od++;
			}
		}
	}
	printf("%lld\n", od);
	printf("%lld\n", ev);
	return 0;
}
