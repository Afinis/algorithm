#include<bits/stdc++.h>
using namespace std;
long long n, a[200000+5], ans, sum[200000+5];
int main(){
	scanf("%lld", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	
	sum[0] = a[0];
	for(int i = 1; i < n; i++)
		sum[i] = sum[i-1] + a[i];
	
	for(int i = 0; i < n; i++)
		ans += a[i]*(sum[n-1]-sum[i]);
	
	printf("%lld\n", ans);
	return 0;
}
