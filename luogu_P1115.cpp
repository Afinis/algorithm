#include<bits/stdc++.h>
using namespace std;

long long a[1000000], dp[1000000], mx;

int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	dp[0] = a[0], mx = a[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i-1] + a[i], a[i]);
		mx = max(mx, dp[i]);
	}
	printf("%d", mx);
	return 0;
}
