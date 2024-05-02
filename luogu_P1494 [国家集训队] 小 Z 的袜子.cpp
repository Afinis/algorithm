#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int n, m, a[N], sqr, cnt[N]; 
ll sum, r1[N], r2[N];
struct query{
	int l, r, id;
}q[N];

bool cmp(query a, query b){
	if(a.l/sqr != b.l/sqr)
		return a.l < b.l;
	else return a.r < b.r;
}

void del(int i){
	if(cnt[a[i]]>=2){
		sum -= cnt[a[i]]-1;
	}
	cnt[a[i]]--;
}

void add(int i){
	cnt[a[i]]++;
	if(cnt[a[i]]>=2){
		sum += cnt[a[i]]-1;
	}
} 

ll gcd(ll a, ll b){
	return a==0 ? b : gcd(b%a, a);
}

int main(){
	scanf("%d%d", &n, &m);
	sqr = sqrt(n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	} 
	for(int i = 0; i < m; i++){
		int l, r; scanf("%d%d", &l, &r);
		q[i].l = l, q[i].r = r, q[i].id = i;
	}
	sort(q, q+m, cmp);
	int l = 1, r = 0;
	for(int i = 0; i < m; i++){
		if(q[i].l==q[i].r){
			r1[q[i].id] = 0;
			r2[q[i].id] = 1;
			continue;
		}
		while(l < q[i].l) del(l++);
		while(l > q[i].l) add(--l);
		while(r < q[i].r) add(++r);
		while(r > q[i].r) del(r--);
		ll t = (ll)(q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2;
		ll g = gcd(t, sum);
		r1[q[i].id] = sum/g;
		r2[q[i].id] = t/g;
	}
	for(int i = 0; i < m; i++){
		printf("%lld/%lld\n", r1[i], r2[i]);
	}
	return 0;
} 
