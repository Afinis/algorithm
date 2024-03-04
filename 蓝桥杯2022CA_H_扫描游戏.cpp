#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-16;
ll n, l, rk, r[2*100000+5], vis[2*100000+5], epo[2*100000+5], now;
struct node{
	ll x, y, z, rk;
	double d, cos;
};
node e[2*100000+5];
map<pair<ll, ll>, ll> mp;

bool equ(double a, double b){
	if(abs(a-b)<= eps ) return true;
	else return false;
}

bool line(node a, node b){
	if(equ(a.cos, b.cos)){
		if( (a.x>=0&&b.x>=0&&a.y>=0&&b.y>=0) || 
		  	(a.x>=0&&b.x>=0&&a.y<=0&&b.y<=0) ||
		  	(a.x<=0&&b.x<=0&&a.y>=0&&b.y>=0) ||
		  	(a.x<=0&&b.x<=0&&a.y<=0&&b.y<=0) ){
		  	return true;
		}  
	}
	return false;
}

bool mycmp(node a, node b){
	if(line(a , b)) 
		return a.d<=b.d+eps;
	if(a.x >= 0){
		if(b.x >= 0) return a.cos+eps > b.cos;
		else return true;
	}else{
		if(b.x < 0) return a.cos < b.cos+eps;
		else return false;
	}	
	return false;
} 


int main(){
	scanf("%lld%lld", &n, &l);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &e[i].x, &e[i].y, &e[i].z);
		e[i].d = sqrt(e[i].x*(double)e[i].x+e[i].y*(double)e[i].y);
		if(e[i].x==0 && e[i].y == 0){
			e[i].cos = 1;
		}else
			e[i].cos = e[i].y/e[i].d;
		mp[{e[i].x, e[i].y}] = i;
	}
	sort(e, e+n, mycmp);
	
	bool en = true;
	while(en){
		int c = 0;
		now++;
		for(int i = 0; i < n; i++){
			if(e[i].d<=l+eps && vis[i]==0){
				epo[mp[{e[i].x, e[i].y}]] = now;
				c=1;
				vis[i]=1;
				l += e[i].z;
				if(i){
					if(epo[mp[{e[i-1].x, e[i-1].y}]]==now&&line(e[i], e[i-1])){
						r[mp[{e[i].x, e[i].y}]] = r[mp[{e[i-1].x, e[i-1].y}]];
						rk++;
					}else r[mp[{e[i].x, e[i].y}]] = ++rk;				
				}else r[mp[{e[i].x, e[i].y}]] = ++rk;	
			}
		}
		if(c==0) break;
	}
	
	for(int i = 0; i < n; i++){
		if(i) printf(" ");
		printf("%lld", r[i]==0?-1:r[i]);
	}
	return 0;
}
