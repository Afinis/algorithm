#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000+5;
int n, a[MAX], dp[5000+5][5000+5];
typedef long long ll;
ll sum;
int main(){
	scanf("%d", &n);	
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		dp[i][i] = a[i];
		sum += dp[i][i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			dp[i][j] = dp[i][j-1]^a[j];
			sum += dp[i][j];
		}
	}
	printf("%lld\n", sum);
	return 0;
}
