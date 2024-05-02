#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6, INF = 1e17;
ll X, Y, n, vis[N], ans, mi = INF; 
struct node{
	ll x1, y, x2;
	ll id;
}a[N];

bool cmp1(node a, node b){
	if(a.y != b.y){
		return a.y > b.y;
	}else return a.x1 < b.x1;
}

bool cmp2(node a, node b){
	if(a.y != b.y){
		return a.y > b.y;
	}else return a.x2 < b.x2;
}

int main(){
	scanf("%lld%lld%lld", &n, &X, &Y);
	for(int i = 0; i < n; i++){
		ll x, y, l;
		scanf("%lld%lld%lld", &x, &y, &l);
		a[i] = {x, y, x+l, i};
	}
	sort(a, a+n, cmp1);
	for(int i = 0; i < n; i++){
		double k = (Y-a[i].y)/(double)(X-a[i].x1);
		if(X==-a[i].x1) k = INF-1;
		if(k < mi){
			if(!vis[a[i].id]){
				vis[a[i].id]++;
				ans++;
			}
			mi = k;
		}
	}
	sort(a, a+n, cmp2);
	for(int i = 0; i < n; i++){
		double k = (Y-a[i].y)/(double)(X-a[i].x2);
		if(X==-a[i].x1) k = INF-1;
		if(k < mi){
			if(!vis[a[i].id]){
				vis[a[i].id]++;
				ans++;
			}
			mi = k;
		}
	}
	printf("%lld", ans);
	return 0;
}
