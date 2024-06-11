#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, cro;
unordered_map<string, int> a, b, uni;

void conv(string &s){
	for(int i = 0; i < s.size(); i++){
		if('A' <= s[i] && s[i] <= 'Z'){
			s[i] = s[i] - 'A' + 'a';
		}
	}
}

int main(){
	cin>>n>>m;
	string s;
	for(int i = 0; i < n; i++){
		cin>>s;
		conv(s);
		a[s]++;
		uni[s]++; 
	}
	for(int i = 0; i < m; i++){
		cin>>s;
		conv(s);
		b[s]++;
		uni[s]++; 
	}
	for(auto it = a.begin(); it != a.end(); it++){
		if(b.count(it->first)){
			cro++;
		}
	}
	cout<<cro<<endl<<uni.size()<<endl;
	return 0;
}
