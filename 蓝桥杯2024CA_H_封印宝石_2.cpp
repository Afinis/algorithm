#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k;
int a[N], ans[N];
#define ls p*2
#define rs p*2+1

struct ele{
	int x, i;
	bool operator<(const ele t){
		if(x == t.x){
			return i > t.i;
		}else{
			return x < t.x;
		}
	}
	bool operator>(const ele t){
		if(x == t.x){
			return i < t.i;
		}else{
			return x > t.x;
		}
	}
};

struct node{
	int l, r;
	ele mx, sm;
}t[N*4];


ele maxx(ele a, ele b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

void pushUp(int p){
	if(t[ls].mx < t[rs].mx){
		t[p].mx = t[rs].mx;
		t[p].sm = maxx(t[ls].mx, t[rs].sm);
	}else if(t[ls].mx > t[rs].mx){
		t[p].mx = t[ls].mx;
		t[p].sm = maxx(t[rs].mx, t[ls].sm);
	}else{
		t[p].mx = t[ls].mx;
		t[p].sm = maxx(t[ls].sm, t[rs].sm);
	}

}

void build(int p, int l, int r){
	t[p].l = l, t[p].r = r;
	if(l == r){
		t[p].mx = ele{a[l], l};
		t[p].sm = ele{-100, 100};
		return;
	}
	int mi = l+r>>1;
	build(ls, l, mi);
	build(rs, mi+1, r);
	pushUp(p);
}

pair<ele, ele> query2(int p, int l, int r){
	if(l <= t[p].l &&  t[p].r <= r){
		return {t[p].mx, t[p].sm};
	}
	int mi = t[p].l + t[p].r >> 1;
	pair<ele, ele> L = pair<ele, ele>{ele{-100, 100}, ele{-100, 100}};
	pair<ele, ele> R = L, ans;
	if(l <= mi){
		L = query2(ls, l, r);
	}
	if(mi < r){
		R = query2(rs, l, r);
	}

	if(L.first < R.first ){
		ans.first = R.first;
		ans.second = maxx(R.second, L.first);
	}else if(L.first > R.first ){
		ans.first = L.first;
		ans.second = maxx(R.first, L.second);
	}else{
		ans.first = L.first;
		ans.second = maxx(R.second, L.second);
	}
	pushUp(p);
	return ans;
}

void update(int p, int pos, int v){
	if(t[p].l == t[p].r){
		t[p].mx = ele{v, pos};
		t[p].sm = ele{-100, 100};
		return;
	}
	int mi = t[p].l + t[p].r >> 1;
	if(pos <= mi){
		update(ls, pos, v);	
	}else{
		update(rs, pos, v);
	}
	pushUp(p);
}

int main(){
	cin>>n>>k;	
	for(int i = 1; i <= n; i++) cin>>a[i];
	build(1, 1, n);
	for(int i = 1; i <= n; i++){
		if(k < 0){
			ans[i] = -1;
			continue;
		}
		ele q = query2(1, i, min(n, i+k)).first;
		int pos = q.i;
		if(a[pos] == -1){
			ans[i] = -1;
			continue;
		}
		if(ans[i-1] == -1 || ans[i-1] != a[pos]){
			ans[i] = a[pos];
			a[pos] = -1;
			update(1, pos, -1);
			k -= pos-i; 
		}else{
			q = query2(1, i, min(n, i+k) ).second;
			pos = q.i;
			if(a[pos] == -1){
				ans[i] = -1;
				continue;
			}
			ans[i] = a[pos];
			a[pos] = -1;
			update(1, pos, -1);
			k -= pos-i; 
		}
	}
	for(int i = 1; i <= n; i++){
		if(i!=1) cout<<" ";
        cout<<ans[i];
    }
	return 0;
} 
