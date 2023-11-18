#include<bits/stdc++.h>
using namespace std;

int n;
string s[25], r;
char be;
map<string, int> vis;
int concat(string a, string b){
	for(int i = 1; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			int ap = i, bp = j;
			while(ap < a.size() && bp < b.size() && b[bp] == a[ap]){
				ap++;
				bp++;
			}
			if(ap == a.size() && bp != b.size()){
				return i;
			}
		}
	}
	return -1;
}


void dfs(string a, int c){
	if(c==n){
		if(r.size() < a.size()){
			r = a;	
		}
		return;
	}
	for(int i = 0; i < n; i++){
		if(vis.count(s[i]) ==0){
			int p = concat(a, s[i]);
			if(p != -1){
				vis[s[i]] = 1;
				dfs( a.substr(0, p)+s[i] , c+1);
				vis[s[i]] = 0;
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s[i];
	}
	cin>>be;
	for(int i = 0; i < n; i++){
		if(be == s[i][0]){
			vis[s[i]] = 1;
			dfs(s[i], 0);
			vis[s[i]] = 0;
		}
	}
	cout<<r.size()<<endl;
	
	return 0;
}
