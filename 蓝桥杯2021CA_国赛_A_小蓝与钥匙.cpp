#include <bits/stdc++.h>
using namespace std;
int n = 14;
typedef long long ll;
ll dfs(ll n){
	if(n==2) return 1;
	if(n==1) return 0;
	return (n-1)*(dfs(n-2) + dfs(n-1));
}

int main(){
	ll ans = 1;
	cout<<dfs(14)<<endl;
	for(int i = 15; i <= 28; i++)
		ans *= i;
	for(int i = 1; i <= 14; i++)
		ans /= i;
	cout<<ans<<endl;
	cout<<ans*dfs(14)<<endl;
    return 0;
}
