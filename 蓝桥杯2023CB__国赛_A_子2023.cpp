#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2023, M = 1e6;
ll f2[M], f20[M], f202[M], f2023[M];
string s;
int main(){
	for(ll i = 1; i <= N; i++)
		s+=to_string(i);
	ll L = s.size();
	for(ll i = 1; i < L; i++){
		if(s[i]=='2')
			f2[i] = f2[i-1] + 1;
		else
			f2[i] = f2[i-1];
	}
	for(ll i = 1; i < L; i++){
		if(s[i]=='0')
			f20[i] = f2[i] + f20[i-1];
		else
			f20[i] = f20[i-1];
	}
	for(ll i = 1; i < L; i++){
		if(s[i]=='2')
			f202[i] = f20[i] + f202[i-1];
		else
			f202[i] = f202[i-1];
	}
	for(ll i = 1; i < L; i++){
		if(s[i]=='3')
			f2023[i] = f202[i] + f2023[i-1];
		else
			f2023[i] = f2023[i-1];
	}
	cout<<f2023[L-1]<<endl; // 5484660609
	return 0;
}
