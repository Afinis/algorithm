#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353, N = 1e6;
ll n, a[N], m, ans;

bool check(int i){
	int t = 0;
	for(int k = 0; k < 5 && i-k>0; k++){
		t+=a[i-k];
	}
	return t<=m;
}

void dfs(int i){
	if(i==n+1){
		ans++;
		return;
	}
	for(int j = i%2; j<10; j+=2){
		a[i] = j;
		if(check(i)){
			dfs(i+1);
		}
	}
}

int main(){
	scanf("%lld%lld", &n, &m);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
