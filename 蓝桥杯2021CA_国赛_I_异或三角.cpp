#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 32;
// dp[p][sta][fulc]��ǰpλ����ǰ���������ѹ��Ϊ״̬sta��
// ��pλ��Ҳ�ǵ�ǰλ��a��1��0 
ll dp[N][8][2], a[N];

ll dfs(ll p, ll sta, bool fulc){
	if(p < 0) return sta == 7; // ͬʱ������������
	if(~dp[p][sta][fulc]) return dp[p][sta][fulc];
	ll dig = fulc ? a[p] : 1;
	ll res = 0;
	for(ll k = 0; k <= dig; k++){
		if(k==0){
			ll b = sta&1, c = sta>>1&1;
			res += dfs(p-1, sta, fulc && (k==dig));
			if(b==1&&c==1){
				// (a_i, b_i, c_i) = (0, 1, 1)������������	
				// fulc && (k==dig) ��֤ a <= n 
				res += dfs(p-1, sta|4, fulc && (k==dig)); 
			}
		}
		if(k==1){
			// (a_i, b_i, c_i) = (1, 0, 1)����������һ 
			res += dfs(p-1, sta|1, fulc && (k==dig)); 
			// (a_i, b_i, c_i) = (1, 1, 0)���������ƶ� 
			res += dfs(p-1, sta|2, fulc && (k==dig)); 
		} 
	}
	return dp[p][sta][fulc]=res;
} 

int main(){
	ll t; scanf("%lld", &t); 
	while(t--){
		ll n; scanf("%lld", &n);
		// ��ʼ����������~�ж�dp�Ƿ���ֵ
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
