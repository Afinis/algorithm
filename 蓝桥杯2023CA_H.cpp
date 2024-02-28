#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000+5;
typedef long long ll;
ll n, a[MAX], p[MAX], w[MAX][2], sum;
int main(){
	scanf("%lld", &n);	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	p[1] = a[1];
	for(int i = 2; i <= n; i++)
		p[i] = a[i] ^ p[i-1];	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 20; j++)
			w[j][(p[i]>>j)&1]++;		
	}
	for(int j = 0; j < 20; j++)
		sum += w[j][0] * w[j][1] * (1<<j);
	printf("%lld\n", sum);
	return 0;
}
