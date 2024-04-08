#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int T, n, t[N], d[N], l[N], en=0;
int vis[N];

void dfs(int i, int st, int c){
	if(c==n){
		en=1;
		return;
	}
	vis[i] = 1;
	for(int j = 0; j < n; j++){
		if(!vis[j]){
			if(t[j] <= st && st <= t[j]+d[j]){
				dfs(j, st+l[j], c+1);
			}else if(st <= t[j]+d[j]){
				dfs(j, t[j]+l[j], c+1);
			}
		}
	}
	vis[i] = 0;
}

int main(){
	cin>>T;
	for(int i = 0; i < T; i++){
		cin>>n;
		for(int j = 0; j < n; j++){
			cin>>t[j]>>d[j]>>l[j];
		}
		en = 0;
		for(int j = 0; j < n; j++){
			dfs(j, t[j]+l[j], 1);
			if(en){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(en==0){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
