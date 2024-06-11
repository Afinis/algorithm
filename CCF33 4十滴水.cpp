#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int c, m, n; 
struct node{
	int la, nx, v, p;
};
node e[N];
map<int , node> mp;

bool cmp(node x, node y){
	return x.p < y.p;
}

void check(int p){
	if(!mp.count(p) || mp[p].v < 5) return;
	
	if(p-1 >= 1) check(p-1);
	
	int nx = mp[p].nx, la = mp[p].la;
	if(nx){
		mp[nx].v++;
		mp[nx].la = la;
	}
	if(la){
		mp[la].v++;
		mp[la].nx = nx;
	}
	mp.erase(p);
	if(la) check(la);
	if(nx) check(nx);
}

int main(){
	scanf("%d%d%d", &c, &m, &n);
	int nx = 0, la = 0;
	for(int i = 1; i <= m; i++){
		int x, w;
		scanf("%d%d", &x, &w);
		e[i].p = x;
		e[i].v = w;
	}
	sort(e+1, e+1+m, cmp); 
	
	for(int i = 1; i <= m; i++){
		mp[e[i].p] = node{e[i-1].p, e[i+1].p, e[i].v, e[i].p};
	}
	
	for(int i = 1; i <= n; i++){
		int p;
		scanf("%d", &p);
		mp[p].v++;
		if(mp[p].v >= 5){
			check(p);
		}
		printf("%d\n", mp.size());
	}
	return 0;
}
