#include<bits/stdc++.h>
using namespace std;
int n;
string s[25], r;
char be;
map<string, int> vis;
int concat(string a, string b){
    int fin = -1;
	for(int i = 1; i < a.size(); i++){
        int ap = i, bp = 0;
        while(ap < a.size() && bp < b.size() && b[bp] == a[ap]){
            ap++;
            bp++;
        }
        if(ap == a.size() && bp != b.size()) fin = i;
	}
	return fin;
}

void dfs(string a, int c){
    if(r.size() < a.size()) r = a;
    for(int i = 0; i < n; i++){
        if(vis[s[i]] > 0){
            int p = concat(a, s[i]);
            if(p != -1){
                vis[s[i]]--;
                dfs(a.substr(0, p)+s[i] , c+1);
                vis[s[i]]++;
            }
        }
    }
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s[i];
        vis[s[i]] = 2;
	}
	cin>>be;
	for(int i = 0; i < n; i++){
		if(be == s[i][0]){
			vis[s[i]]--;
			dfs(s[i], 0);
			vis[s[i]]++;
		}
	}
	cout<<r.size()<<endl;
	return 0;
}
