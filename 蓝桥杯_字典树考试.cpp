#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10, M = 32;
ll n, a[N], sum[33], ans;

void add(ll x){
	for(ll i = 0; i < M; i++){
		if(x&(1<<i)){
			sum[i]++;
		}
	}
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	add(a[n-1]);
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < M; j++){
			if(a[i]&(1<<j)){
				ans += sum[j];
			}
		}
		add(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
