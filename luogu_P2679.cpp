#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int n, m, K, dp[200+5][200+5], g[200+5][200+5], r = 0;
string a, b;

int main(){
    cin>>n>>m>>K>>a>>b;
    for(int i = n-1; i >= 0; i--){
        for(int j = max(i+m-n, 0) ; j < m; j++){
            for(int k = min(n-i , K); k >= 1; k--){
                if (k == 1){
                    if(m-j <= n && a.substr(i, m-j) == b.substr(j, m-j)){
                        dp[j][1] = 1;
                    }else{
                        dp[j][1] = 0;
                    }
                }else if(a[i]==b[j]){
                    dp[j][k] = g[j+1][k-1] + dp[j+1][k];
                    dp[j][k] %= M;
                }else{
                    dp[j][k] = 0;
                }
                g[j][k] = g[j][k] + dp[j][k];
                g[j][k] %= M;
                if (j == 0 && k == K && a[i] == b[0]){
                    r += dp[0][K];
                    r %= M;
                }
            }
        }
    }
    cout<<r<<endl;
    return 0;
}
