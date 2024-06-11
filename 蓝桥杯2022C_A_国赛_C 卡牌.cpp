#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
ll n, m, A[N], B[N], ans;

bool check(ll x, ll c){
	for(int i = 0; i < n; i++){
		if(A[i] < x){
			ll d = x - A[i];
			if(d > B[i]) return false;
			if(c < d) return false;
			c -= d;
		}
	}
	return true; 
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
    	cin>>A[i];
	}
    for(int i = 0; i < n; i++){
    	cin>>B[i];
	}
	ll hi = 1e11, lo = 0;
	while(lo < hi){
		ll mi = (lo+hi)>>1;
		if(check(mi, m)){
			lo = mi+1;
		}else{
			hi = mi;
		}
	}
	cout<<hi-1<<endl;
    return 0;
}
