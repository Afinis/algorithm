#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n = 2021;
ll w[n*2];
int main(){
	fill(w, w+2*n, (ll)1e16);
	w[0]=0;
	for(ll i = 1; i <= n; i++){
		for(ll l = 0; l < i; l++){
			ll r = i-l-1;
			ll t = 1+ 2*w[l] + 3*w[r] + l*l*r;
			w[i] = min(w[i], t);
		}
	}
	cout<<w[n]<<endl;
	return 0;
}
