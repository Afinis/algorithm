#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10; 
int a[N], n, m, sqr, ans[N], cnt[2][N]; 
struct query{
	int l, r, k, id;
	bool operator<(const query a){
		if(l/sqr != a.l/sqr){
			return l < a.l;
		}else return r < a.r;
	}
}q[N];

void del(int i){
	cnt[1][cnt[0][a[i]]]--;
	cnt[0][a[i]]--;
	cnt[1][cnt[0][a[i]]]++;
}

void add(int i){
	cnt[1][cnt[0][a[i]]]--;
	cnt[0][a[i]]++;
	cnt[1][cnt[0][a[i]]]++;
}

int main(){
	scanf("%d", &n);
	sqr = sqrt(n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		q[i].l = l, q[i].r = r, q[i].k = k, q[i].id = i;
	}
	sort(q, q+m);
	int l = 1, r = 0;
	for(int i = 0; i < m; i++){
		while(l < q[i].l) del(l++);
		while(l > q[i].l) add(--l);
		while(r < q[i].r) add(++r);
		while(r > q[i].r) del(r--);
		ans[q[i].id] = cnt[1][q[i].k];
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
