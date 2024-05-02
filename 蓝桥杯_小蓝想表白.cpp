#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10, M = 1e9+7;
ll n, l[N], lo[N], lov[N], love[N];
string s;

int main(){
	cin>>n>>s;
	l[0] = s[0]=='l' ? 1 : 0;
	for(ll i = 1; i < n; i++){
		l[i] = l[i-1];
		lo[i] = lo[i-1];
		lov[i] = lov[i-1];
		love[i] = love[i-1];
		if(s[i]=='l') l[i]++;
		if(s[i]=='o') lo[i] = (lo[i] + l[i-1])%M;
		if(s[i]=='v') lov[i] = (lov[i] + lo[i-1])%M;
		if(s[i]=='e') love[i] = (love[i] + lov[i-1])%M;
	}
	cout<<love[n-1]%M<<endl;
	return 0;
}
