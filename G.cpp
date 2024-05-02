#include<bits/stdc++.h>
using namespace std;
#define ls 2*p
#define rs 2*p+1
const int N = 1e5+10;
int n, k, a[N], be[N], ed[N], bc, ec, A[N], B[N], ma;

bool cmp(int a, int b){
	return a>b;
}

struct node{
	int l, r, v;
}t[4*1000000+10];

void pushUp(int p){
	t[p].v = max(t[ls].v, t[rs].v);
}

void build(int l, int r, int p){
	t[p].l = l, t[p].r = r, t[p].v=0;
	if(l==r){
		return;
	}
	int mi = l+r>>1;
	build(l, mi, ls);
	build(mi+1, r, rs);
}

int find(int l, int r, int p){
	if(l <= t[p].l && t[p].r <= r){
		return t[p].v;
	}
	int mi = t[p].l+t[p].r>>1;
	int ans = 0;
	if(l <= mi){
		ans = find(l, r, ls);
	}
	if(mi+1 <= r){
		ans = max(find(l, r, rs), ans);
	}
	return ans;
}

void add(int p, int x, int v){
	if(t[p].l == t[p].r){
		t[p].v = max(t[p].v, v);
		return ;
	}
	int mi = t[p].l+t[p].r>>1;
	if(x <= mi){
		add(ls, x, v);
	}else{
		add(rs, x, v);
	}
	pushUp(p);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ma = max(ma, a[i]);
	}
	ed[ec++] = a[0]; A[0] = 1;
	for(int i = 1; i < n; i++){
		if(ed[ec-1] <= a[i]){
			ed[ec++] = a[i];
			A[i] = ec;
		}else{
			int t = upper_bound(ed, ed+ec, a[i])-ed;
			A[i] = t+1;
			ed[t] = a[i];
		}
	}
	be[bc++] = a[n-1]; B[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		if(be[bc-1] >= a[i]){
			be[bc++] = a[i];
			B[i] = bc;
		}else{
			int t = upper_bound(be, be+bc, a[i], cmp)-be;
			B[i] = t+1;
			be[t] = a[i];
		}
	}
	/*
	// 也可以这么求 
	build(1, ma, 1);
	for(int i = 0; i < n; i++){
		A[i] = find(1, a[i], 1)+1;
		add(1, a[i], A[i]); 
	}
	build(1, ma, 1);
	for(int i = n-1; i >= 0; i--){
		B[i] = find(a[i], ma,1)+1;
		add(1, a[i], B[i]); 
	}
	*/
	build(1, ma, 1);
	int ans = k+B[k];
	for(int i = 0; i+k+1 < n; i++){
		add(1, a[i], A[i]);
		int t = find(1, a[i+k+1], 1);
		ans = max(ans, t+k+B[i+k+1]);	
	}
	printf("%d\n", ans);
	return 0;
}
