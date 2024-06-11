#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2025][11][2025];



int main(){
	for(ll i = 0; i <= 2022; i++){
		dp[i][0][0] = 1;
	}
	for(ll i = 1; i <= 2022; i++){
		for(ll j = 1; j <= 10; j++){
			for (ll k = 1; k <= 2022; k++){
				dp[i][j][k] = dp[i-1][j][k]; 
				if (k >= i) 
                    dp[i][j][k] += dp[i-1][j - 1][k - i];
			}	
		}
	}
	
		
	cout<<dp[2022][10][2022]<<endl;
	return 0;
}
