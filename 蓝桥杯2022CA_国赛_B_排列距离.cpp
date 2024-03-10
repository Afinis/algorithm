#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50];
void factorial(int n){
	f[1] = 1;
	for(int i = 2; i <= n; i++)
		f[i] = f[i-1]*i;
}

ll cantor(string s){
	ll rank = 0;
	for(int i = 0; i < s.size(); i++){
		int c=0;
		for(int j = i+1; j < s.size(); j++)
			if(s[j] < s[i]) c++;
		rank += c*f[s.size()-i-1];
	}
	return rank;
}

int main(){
	factorial(18);
	cout<<cantor("acb")<<endl;
	string a="aejcldbhpiogfqnkr", b="ncfjboqiealhkrpgd";
	cout<<cantor(b)-cantor(a)<<endl;
	string c = "abcdefghijklnopqr";
	reverse(c.begin(), c.end());
	cout<<cantor(c)<<endl;
	cout<<cantor(c)-cantor(b)+cantor(a)+1<<endl;
	return 0;
}
