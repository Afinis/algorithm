#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll N = 1e5;
ll n, a[N+10], maxn, cnt[N+10], f[N+10], g[N+10];
template <class T> inline void read(T& x) { x = 0; char c = getchar(); bool f = 0; for (; !isdigit(c); c = getchar()) f ^= (c == '-'); for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48); x = f ? -x : x; }
template <class T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; if (x < 10) putchar(x + 48); else write(x / 10), putchar(x % 10 + 48); }

int main(){
	read(n);
	for(ll i = 0; i < n; i++){
		read(a[i]);
		maxn = max(maxn, a[i]);
		cnt[a[i]]++;
	}
	
	// 两重循环和埃氏筛原理相同 
	for(ll i = 1; i <= maxn; i++){
		for(ll j = i; j <= maxn; j += i){
			// f[i] 数据中是i的倍数的数的个数
			f[i] += cnt[j];
			// g[j] 数据中是j的因数的数的个数
			g[j] += cnt[i];
			// 排除自身 
			if(i==j) f[i]-=1, g[j]-=1;
		}
	}
	
	ll ans = 0;
	// 所有的二元组 
	for(ll i = 1; i <= maxn; i++){
		// (数，倍数) 
		ans += cnt[i] * f[i];  
	}
	
	// 四元组(a_i, a_j, a_k, a_l) 其中i!=k且j!=l
	// 所有情况：A_n^2 
	ans = ans*(ans-1);
	
	// 减去 i==j
	for(ll i = 1; i <= maxn; i++)
		// (数，数，倍数1，倍数2) 
		ans -= cnt[i] * f[i] * (f[i]-1);
	// 减去 k==l
	for(ll i = 1; i <= maxn; i++)
		ans -= cnt[i] * g[i] * (g[i]-1);
	
	// 减去 i==l
	for(ll i = 1; i <= maxn; i++)
		// (数1，数1的因数，数1的倍数，数1)
		// 此时数1的因数和数1的倍数可能会相同（值和下标都相同） 
		ans -= cnt[i] * f[i] * g[i];
	// 减去 j==k
	for(ll i = 1; i <= maxn; i++)
		// (数2的因数，数2，数2，数2的倍数)
		// 此时数2的因数和数2的倍数可能会相同（值和下标都相同） 
		ans -= cnt[i] * f[i] * g[i];
	// 容斥原理，加上被删了两次的情况 
	for(ll i = 1; i <= maxn; i++)
		// (数1，数2，数2，数1)且数1和数2值相同，下标不同 
		ans += cnt[i] * (cnt[i]-1);
		
	write(ans);
	return 0;
}
