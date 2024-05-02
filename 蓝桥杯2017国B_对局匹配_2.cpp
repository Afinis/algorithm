#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k, a[N], c[N], v[N], dp[N], ma, ans; 

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[a[i]]++;
		ma = max(ma, a[i]);
	}
	if(k==0){
		for(int i = 0; i <= ma; i++)
			if(c[i]) ans++;
		
		printf("%d", ans);
		return 0;
	}
	for(int i = 0; i < k; i++){
		int vc = 0;
		for(int j = i; j <= ma; j += k)
			v[vc++] = c[j];
		
		dp[0] = v[0]; dp[1] = max(v[0], v[1]);
		for(int j = 2; j < vc; j++){
			dp[j] = max(dp[j-1], dp[j-2]+v[j]);
		}
		ans += dp[vc-1];
	}
	printf("%d", ans);
	return 0;
}
