#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000, L = 520;
ll ans;
struct node{
	ll y, M, d, h, m, s;
	
	bool operator<(const node t){
		if(y!=t.y) return y < t.y;
		if(M != t.M) return M < t.M;
		if(d != t.d) return d < t.d;
		if(h != t.h) return h < t.h;
		if(m != t.m) return m < t.m;
		return s < t.s;
	}
}e[N];

ll minu(node a, node b){
	ll d = a.d - b.d;
	ll h = a.h - b.h + d*24;
	ll m = a.m - b.m + h*60;
	ll s = a.s - b.s + m*60;
	return s;
}

int main(){
	
	for(int i = 0; i < L; i++){
		ll y, M, d, h, m, s;
		scanf("%lld-%lld-%lld %lld:%lld:%lld", &y,&M,&d,&h,&m,&s);
		e[i] = {y, M, d, h, m, s};
	}
	sort(e, e+L);
	for(int i = 0; i < L; i+=2){
		ans += minu(e[i+1], e[i]);
		if(e[i].M != e[i+1].M){
			cout<<"<<<<<<<<<<<>>>>>>>>>>>>>>"<<endl;
			return 0;
		}
	}
	printf("%lld", ans); // 5101913
	return 0;
}
