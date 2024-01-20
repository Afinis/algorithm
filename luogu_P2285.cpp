#include<bits/stdc++.h>
using namespace std;

struct node{
	int x, y, time;
}a[10000+5];
int n, m, dp[10000+5], r = 1;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d%d%d", &a[i].time, &a[i].x, &a[i].y);
	fill(dp, dp+10000, 1);
	for(int i = 1; i < m; i++){
		for(int j = 0; j < i; j++){
			if(a[i].time - a[j].time >= int(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) ){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		r = max(r, dp[i]);
	}
	
	printf("%d", r);
	return 0;
}
