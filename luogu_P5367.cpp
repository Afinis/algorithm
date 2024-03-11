#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P = 998244353, M = 1e6+10;
ll n, a[M], c[M], f[M];
void fact(){
	f[1]=1;
	for(int i = 2; i < M; i++)
		f[i] = (i*f[i-1])%P;	
}

int lowbit(int x){
	return x & (-x);
}

void add(int x, int k){
	while(x<=n){
		c[x]+=k;
		x += lowbit(x);
	}
} 

int getSum(int x){
	int cnt = 0;
	while(x){
		cnt += c[x];
		x -= lowbit(x);
	}
	return cnt;
}

ll cantor(){
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int t = getSum(a[i]);
		ans += ((a[i]-1-t)*f[n-i])%P;
		ans %= P;
		add(a[i], 1);
	}
	return ans;
}

int main(){
	fact();
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	printf("%lld", cantor()+1);
	return 0;
}
