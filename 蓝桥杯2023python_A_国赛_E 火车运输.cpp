#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n, A, B, dp[N][N], w[N]; 

int main(){
	cin>>n>>A>>B;
	for(int i = 1; i <= n; i++){
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++){
		for(int a = A; a >= 0; a--){
			for(int b = B; b >= 0; b--){
				if(a-w[i] >= 0){
					dp[a][b] = max(dp[a][b], dp[a-w[i]][b]+w[i]);
				}
				if(b-w[i] >= 0){
					dp[a][b] = max(dp[a][b], dp[a][b-w[i]]+w[i]);
				}
			}
		}
	}
	cout<<dp[A][B]<<endl;
	return 0;
}
