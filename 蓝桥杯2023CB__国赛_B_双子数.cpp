#include<bits/stdc++.h>
using namespace std;
typedef long long ll; // 23333333333333
const ll lo = 2333, hi = 23333333333333, N = 1e7;
ll notP[N], p[N], pc, sq, sum[N+10], ans;

void Euler(){
	notP[1] = 1;
	for(ll i = 2; i < N; i++){
		if(notP[i]==0){
			p[pc++]=i;
		}
		for(ll j = 0; j<pc && p[j]*i<N; j++){
			notP[p[j]*i] = 1;
			if(i%p[j]==0){
				break;
			}
		}
	}
}

int main(){
	sq = sqrt(hi);
	Euler();
	for(ll i = 2; i < N; i++){
		if(notP[i] == 0){
			sum[i] = sum[i-1]+1;
		}else{
			sum[i] = sum[i-1];
		}
	}
	for(ll i = 2; i <= sq; i++){
		if(notP[i] == 0){
			ll a = i*i;
			ll b = min(i-1, (ll)sqrt(hi/a));
			ans += sum[b];
		}
	}
	cout<<sq<<endl; //4830458
	cout<<ans<<endl; //947306 - 13 = 947293
	return 0;
}
