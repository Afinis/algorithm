#include<bits/stdc++.h>
using namespace std;
const int N = 10000+5;
int n;
string s[N], r;
bool mycmp(string a, string b){
	return a+b < b+a;
}
int main(){
	cin>>n;
	for(int i = 0; i < n; i++) cin>>s[i];	
	sort(s, s+n, mycmp);
	for(int i = 0; i < n; i++) r += s[i];	
	while(r.size()!=0 && r[0]=='0') r = r.substr(1);
	r.size()==0? cout<<0<<endl : cout<<r<<endl;
	return 0;
}
