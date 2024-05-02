#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, a[N];

unordered_map<int, int> mp;
struct node{
	int l, r;
};

bool cmp(node a, node b){
	if(a.l != b.l){
		return a.l < b.l;
	}
	return a.r < b.r;
}

vector<node> v;

void deFac(int x, int id){
	int sq = sqrt(x);
	for(int i = 2; i <= sq; i++){
		if(x % i == 0){
			if(mp.count(i)){
				v.push_back(node{mp[i], id});
			}else{
				mp[i] = id;
			}
			while(x % i == 0){
				x /= i;
			}
		}
	}
	if(x!=1){
		if(mp.count(x)){
			v.push_back(node{mp[x], id});
		}else{
			mp[x] = id;
		}
	}
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		deFac(a[i], i);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d %d\n", v[0].l, v[0].r);
	return 0;
}
