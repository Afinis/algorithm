#include<bits/stdc++.h>
using namespace std;
const int N = 4;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int g[6][6], vis[6][6]; 
unordered_map<string, long long> mp;
bool check(int x, int y){
	if(1<=x&&x<=N&&1<=y&&y<=N&&g[x][y]==0){
		return true;
	}
	return false;
}

void dfs(int x, int y, int k){
	g[x][y] = k;
	if(k==16){
		string t;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				t += to_string(g[i][j]);
				if(mp.size()<2){
					cout<<g[i][j]<<" ";
				}
			}
			if(mp.size()<2) cout<<endl;
		}
		mp[t]++;
		g[x][y] = 0;
		return;
	}
	for(int i = 0; i < 4; i++){
		int nx = x+X[i], ny = y+Y[i];
		if(check(nx, ny)){
			dfs(nx, ny, k+1);
		}
	}
	g[x][y] = 0;
}

int main(){
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			dfs(i, j, 1);
		}
	cout<<mp.size()<<endl; // 552
	return 0;
}
