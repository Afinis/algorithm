#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 2019, ans=0; 

bool check(ll i){
	while(i){
		ll t = i%10;
		if(t==2 || t==0 || t==1 || t==9){
			return true;
		}
		i /= 10;
	}
	return false;
}

int main(){
	for(int i = 1; i <= n; i++){
		if(check(i)){
			ans += i*i;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
