#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 32;
// dp[p][sta][fulc]，前p位，当前满足的限制压缩为状态sta，
// 第p位（也是当前位）a是1或0 
ll dp[N][8][2], a[N];

ll dfs(ll p, ll sta, bool fulc){
	if(p < 0) return sta == 7; // 同时满足所有限制
	if(~dp[p][sta][fulc]) return dp[p][sta][fulc];
	ll dig = fulc ? a[p] : 1;
	ll res = 0;
	for(ll k = 0; k <= dig; k++){
		if(k==0){
			ll b = sta&1, c = sta>>1&1;
			res += dfs(p-1, sta, fulc && (k==dig));
			if(b==1&&c==1){
				// (a_i, b_i, c_i) = (0, 1, 1)，满足限制三	
				// fulc && (k==dig) 保证 a <= n 
				res += dfs(p-1, sta|4, fulc && (k==dig)); 
			}
		}
		if(k==1){
			// (a_i, b_i, c_i) = (1, 0, 1)，满足限制一 
			res += dfs(p-1, sta|1, fulc && (k==dig)); 
			// (a_i, b_i, c_i) = (1, 1, 0)，满足限制二 
			res += dfs(p-1, sta|2, fulc && (k==dig)); 
		} 
	}
	return dp[p][sta][fulc]=res;
} 

int main(){
	ll t; scanf("%lld", &t); 
	while(t--){
		ll n; scanf("%lld", &n);
		// 初始化，后续用~判断dp是否有值
		memset(dp, -1, sizeof(dp));
		ll l = -1;
		while(n){
			a[++l] = n%2;
			n /= 2;
		}
		printf("%lld\n", dfs(l, 0, 1) * 3 );
	}
	return 0;
}
