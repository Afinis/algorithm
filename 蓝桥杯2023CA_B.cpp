#include<bits/stdc++.h>
using namespace std;
//dp[i][s] 表示前i题，第i题答对（s>0），分数为s的方案数 
long long dp[35][110], r;
int main(){
	dp[1][10] = 1;
	dp[1][0] = 1;
	for(int i = 2; i <= 30; i++)
		for(int s = 0; s <= 100; s+=10)
			if(s){
				dp[i][s] = dp[i-1][s-10];
			}else
				for(int k = 0; k < 100; k += 10)
					dp[i][0] += dp[i-1][k];
	for(int i = 0; i <= 30; i++)
		r += dp[i][70];
	cout<<r;
	return 0; 
}
