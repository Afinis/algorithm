#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, k;

int main(){
	cin>>t;
	for(int i = 0; i < t; i++){
		cin>>n>>k;
		if(n-1<=k){
			cout<<1<<endl;
			continue;
		}
		n = n-k-1;
		ll r = n/k;
		if(n%k) r++;
		cout<<r<<endl;
	}
	return 0;
}
