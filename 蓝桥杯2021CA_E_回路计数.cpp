#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int n = 21;
ll g[25][25], dp[1<<22][22], ans;
int gcd(int a, int b){
	return  a==0 ? b : gcd(b%a, a);
}

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++)
			if(gcd(i, j)==1)
				g[i][j] = g[j][i] = 1;
	}
	dp[1][1]=1;
	for(int i = 1; i < (1<<n); i++){
		for(int j = 1; j <= n; j++){
			if(!(i&(1<<(j-1)))) continue;
			for(int k = 1; k <= n; k++)
				if(g[j][k] && !(i&(1<<(k-1))))
					dp[i|(1<<(k-1))][k] += dp[i][j];	
		}
	}
	for(int i = 2; i <= n; i++)
		if(g[i][1])
			ans += dp[(1<<21)-1][i];
	cout<<ans<<endl;
	return 0;
}
