#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll n, ans = 1;

int main(){
	cin>>n;
	ans = n*(n-1)/2;
	for(int i = 3; i <= n; i++){
		ans = (ans*i)%M;
	}
	cout<<(ans)%M<<endl;
	return 0;
}
