#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[15], b[15], r = 10000000, n;

void dfs(int i, ll cs, ll cb){
	if(i >= n){
		if(cs == 1 && cb == 0) return;
		if((ll)abs(cs-cb) < r) r = abs(cs-cb);
		return;
	}
	dfs(i+1, cs*s[i], cb+b[i]);
	dfs(i+1, cs, cb);
}

int main(){
	cin>>n;
	for(int i = 0;i < n; i++) cin>>s[i]>>b[i];
	dfs(0, 1, 0);
	cout<<r<<endl;
}
