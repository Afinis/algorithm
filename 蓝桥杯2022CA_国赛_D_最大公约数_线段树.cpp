#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, a[N], ans=1e9; 

struct node{
	int l, r, g;
}t[N*4];

int gcd(int a, int b){
	return a==0 ? b : gcd(b%a, a);
}

void pushUp(int p){
	t[p].g = gcd(t[p*2].g, t[p*2+1].g);
}

void build(int p, int l, int r){
	t[p].l = l, t[p].r = r;
	if(l==r){
		t[p].g = a[l];
		return;
	}
	int mi = l+r>>1;
	build(p*2, l, mi);
	build(p*2+1, mi+1, r);
	pushUp(p);
}

int query(int p, int l, int r){
	if(l <= t[p].l && t[p].r <= r){
		return t[p].g;
	}
	int mi = t[p].l + t[p].r >> 1;
	int g = -1, g2 = -1;
	if(l <= mi){
		g = query(p*2, l, r);
	}
	
	if(r > mi){
		g2 = query(p*2+1, l, r);
	}
	if(g!=-1 && g2 == -1) return g;
	if(g2!=-1 && g == -1) return g2;
	return __gcd(g, g2);
}


int main(){
	cin>>n;
	int c = 0;
	
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i]==1) c++;
	}
	if(c){
		cout<<n-c<<endl;
		return 0;
	}
	build(1, 1, n);
	
	if(query(1, 1, n) != 1){
		cout<<-1<<endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		int lo = i+1, hi = n+1;
		while(lo < hi){
			int mi = lo+hi>>1;
			if(query(1, i, mi) == 1){
				hi = mi;
			}else{
				lo = mi+1;
			}
		}
		if(query(1, i, hi) == 1){
			ans = min(ans, hi-i);
		}
	} 
	cout<<n-1+ans<<endl;
	return 0;
}

