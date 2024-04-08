#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+10;
int k, n, f[M];
long long ans;
string s;
char a, b;

int main(){
	cin>>k>>s;
	n = s.size();
	string t;
	cin>>t; a=t[0];
	cin>>t; b=t[0];
	for(int i = n-1; i >= 0; i--){
		if(s[i]==b && i-k+1>=0){
			f[i-k+1]++;
		}
	}
	for(int i = n-1; i>0; i--){
		f[i-1] += f[i];
	}
	for(int i = 0; i < n; i++){
		if(s[i]==a){
			ans+=f[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
