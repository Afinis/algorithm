#include<bits/stdc++.h>
using namespace std;
string s;
unordered_map<string, int> sc;
unordered_map<int, int> cs;

int main(){
	cin>>s;
	for(int l = 1; l <= s.size(); l++){
		for(int j = 0; j+l-1 < s.size(); j++){
			sc[s.substr(j, l)]++;
		}
	}
	for(auto it = sc.begin(); it!=sc.end(); it++){
		cs[it->second]++;
	}
	for(int i = 1; i <= s.size(); i++){
		cout<<cs[i]<<endl;
	}
	return 0;
}
