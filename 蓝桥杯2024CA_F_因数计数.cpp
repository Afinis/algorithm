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
	
	// ����ѭ���Ͱ���ɸԭ����ͬ 
	for(ll i = 1; i <= maxn; i++){
		for(ll j = i; j <= maxn; j += i){
			// f[i] ��������i�ı��������ĸ���
			f[i] += cnt[j];
			// g[j] ��������j�����������ĸ���
			g[j] += cnt[i];
			// �ų����� 
			if(i==j) f[i]-=1, g[j]-=1;
		}
	}
	
	ll ans = 0;
	// ���еĶ�Ԫ�� 
	for(ll i = 1; i <= maxn; i++){
		// (��������) 
		ans += cnt[i] * f[i];  
	}
	
	// ��Ԫ��(a_i, a_j, a_k, a_l) ����i!=k��j!=l
	// ���������A_n^2 
	ans = ans*(ans-1);
	
	// ��ȥ i==j
	for(ll i = 1; i <= maxn; i++)
		// (������������1������2) 
		ans -= cnt[i] * f[i] * (f[i]-1);
	// ��ȥ k==l
	for(ll i = 1; i <= maxn; i++)
		ans -= cnt[i] * g[i] * (g[i]-1);
	
	// ��ȥ i==l
	for(ll i = 1; i <= maxn; i++)
		// (��1����1����������1�ı�������1)
		// ��ʱ��1����������1�ı������ܻ���ͬ��ֵ���±궼��ͬ�� 
		ans -= cnt[i] * f[i] * g[i];
	// ��ȥ j==k
	for(ll i = 1; i <= maxn; i++)
		// (��2����������2����2����2�ı���)
		// ��ʱ��2����������2�ı������ܻ���ͬ��ֵ���±궼��ͬ�� 
		ans -= cnt[i] * f[i] * g[i];
	// �ݳ�ԭ�����ϱ�ɾ�����ε���� 
	for(ll i = 1; i <= maxn; i++)
		// (��1����2����2����1)����1����2ֵ��ͬ���±겻ͬ 
		ans += cnt[i] * (cnt[i]-1);
		
	write(ans);
	return 0;
}
