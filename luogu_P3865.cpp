#include<bits/stdc++.h>
using namespace std;
const int M = 2*1e5, logn = 20;
int n, m, a[M+10], f[M+10][logn+5], lg[M+10];

void initLog(){
	lg[2]=1;
	for(int i = 3; i <= M; i++)
		lg[i]=lg[(i)/2]+1;
}

int main(){
	initLog();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		f[i][0] = a[i];
	}
	for(int j = 1; j < logn; j++)
		for(int i = 1; i+(1<<(j-1)) <= n; i++)
			f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);		
	for(int i = 1; i <= m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		int s = lg[r-l+1];
		printf("%d\n", max(f[l][s], f[r-(1<<s)+1][s]));
	}
	return 0;
}
