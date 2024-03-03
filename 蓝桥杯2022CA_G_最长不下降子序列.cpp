#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000+5;
int n, k, a[MAX], mx, dpl[MAX], dpr[MAX], ans;

struct node{
	int l, r, mx, cnt;
}t[40*MAX];

void build(int p, int l, int r){
	t[p].l = l, t[p].r = r, t[p].cnt = t[p].mx = 0;
	if(l==r) return;
	int mi = (l+r)>>1;
	build(2*p, l, mi);
	build(2*p+1, mi+1, r);
}

int query(int p, int l, int r){
	if(t[p].l==l && t[p].r==r) return t[p].mx;
	int mi = (t[p].l+t[p].r)>>1;
	if(r <= mi) return query(p*2, l, r);
	else if(l > mi) return query(p*2+1, l, r);
	else return max(query(p*2, l, mi), query(p*2+1, mi+1, r) );
}

void update(int p, int i, int val){
	if(t[p].l == t[p].r){
		t[p].mx = val;
		t[p].cnt++;
		return ;
	}
	int mi = (t[p].l + t[p].r)>>1;
	if(i <= mi){
		update(p*2, i, val);
	}else{
		update(p*2+1, i, val);
	}
	t[p].mx = max(t[p*2].mx, t[p*2+1].mx);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	
	build(1, 1, mx);
	for(int i = 1; i <= n; i++){
		dpl[i] = query(1, 1, a[i])+1;
		update(1, a[i], dpl[i]);
	}
	build(1, 1, mx);
	for(int i = n; i >= 1; i--){
		dpr[i] = query(1, a[i], mx)+1;
		update(1, a[i], dpr[i]);
	}
	
	build(1, 1, mx);	
	for(int i = n; i >= 1+k+1; i--){
		update(1, a[i], dpr[i]);
		ans=max(ans, dpl[i-k-1]+query(1, a[i-k-1], mx));
	}
	printf("%d", ans+k);
	return 0;
} 
