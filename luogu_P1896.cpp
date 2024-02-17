#include<bits/stdc++.h>
using namespace std;
int n, K, sta[5000], num[5000], cs;
long long dp[10][5000][100], r;
void dfs(int i, int s, int c){
	if(i >= n || c > K){
		sta[cs] = s;
		num[cs] = c;
		cs++;
		return;
	}
	dfs(i+1, s, c);
	dfs(i+2, s|(1<<i), c+1);
}

int main(){
	cin>>n>>K;
	dfs(0, 0, 0);
	for(int j = 0; j < cs; j++)
		dp[0][j][num[j]]=1;	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < cs; j++){
			for(int k = num[j]; k <= K; k++){
				for(int t = 0; t < cs; t++){
					if( !(sta[j]&sta[t]) && !(sta[j]&(sta[t]<<1)) && !((sta[j]<<1)&sta[t]))
						dp[i][j][k] += dp[i-1][t][k-num[j]];
				}
			}
		}	
	}
	for(int j = 0; j < cs; j++)
		r+=dp[n-1][j][K];	
	cout<<r<<endl;
	return 0;
}
