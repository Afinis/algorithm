#include<bits/stdc++.h>
using namespace std;
string s;
int k, n;
long long ans;
int main(){
	cin>>n>>k>>s;
	for(int i = 0; i < n; i++){
		if(s[i]=='M' || s[i]=='T'){
			ans++;
		}else if(k){
			k--;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
