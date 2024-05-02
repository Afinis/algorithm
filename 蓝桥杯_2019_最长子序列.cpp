#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, t; 
int main(){
	cin>>s>>t;
	int c = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t[c]) c++; 
	}
	cout<<c<<endl;
	return 0;
}
