#include<bits/stdc++.h>
using namespace std;
const int N = 3e4+10, M = 2e5+10, A = 1e6+10;

int a[N], n, m, ans[M], sqr, cnt[A], sum;

struct query{
	int l, r, id;
}q[M];

bool cmp(query a, query b){
	if(a.l/sqr != b.l/sqr){
		return a.l < b.l;
	}else{
		return a.r < b.r;
	}
}

// 常数优化 
bool cmp2(query a, query b){
	if(a.l/sqr != b.l/sqr){
		return a.l < b.l;
	}else if((a.l/sqr)&1){
		return a.r < b.r;
	}else{
		return a.r > b.r;
	}
}

void add(int i){
	cnt[a[i]]++;
	if(cnt[a[i]]==1) sum++;
}

void del(int i){
	cnt[a[i]]--;
	if(cnt[a[i]]==0) sum--;
}
int main(){
	scanf("%d", &n);
	sqr = sqrt(n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r; scanf("%d%d", &l, &r);
		q[i].l = l, q[i].r = r, q[i].id = i;
	}
	sort(q, q+m, cmp2);
	int l = 1, r = 0; // 初始化 l比r大1（且在[1,n]内） 
	for(int i = 0; i < m; i++){
		while(l < q[i].l) del(l++);
		while(l > q[i].l) add(--l);
		while(r < q[i].r) add(++r);
		while(r > q[i].r) del(r--);
		ans[q[i].id] = sum; 
	}
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
