#include<bits/stdc++.h>
using namespace std;
int cf, cb, en;
int X[] = {1, 1, -1, -1, 2, 2, -2, -2};
int Y[] = {2, -2, 2, -2, 1, -1, 1, -1};
string be, ed="111110111100*110000100000";
unordered_map<string, int> vis;
int check(int x, int y){
	if(0 <= x && x < 5 && 0 <= y && y < 5)
		return true;
	return false;
}
void dfs_forward(int d, string sta, int x, int y){
	if(d == cf) vis[sta] = 1;
	if(d > cf) return;
	for(int i = 0; i < 8; i++){
		int nex = x + X[i], ney = y + Y[i];
		if(check(nex, ney)){
			string newsta = sta;
			swap(newsta[nex*5+ney], newsta[x*5+y]);
			dfs_forward(d+1, newsta, nex, ney);
		}
	}
}

void dfs_backward(int d, string sta, int x, int y){
	if(en || d > cb) return;
	if(vis[sta]){
		en = 1;
		return;
	}
	for(int i = 0; i < 8; i++){
		int nex = x + X[i], ney = y + Y[i];
		if(check(nex, ney)){
			string newsta = sta;
			swap(newsta[nex*5+ney], newsta[x*5+y]);
			dfs_backward(d+1, newsta, nex, ney);
		}
	}
}

int main(){
	int T; cin>>T;
	for(int i = 0; i < T; i++){
		be = "";
		int ix, iy;
		for(int x = 0; x < 5; x++){
			string t;
			cin>>t;
			be += t;	
		}
		int xin = find(be.begin(), be.end(), '*') - be.begin();
		ix = xin/5, iy = xin%5;
		int k = 0;
		en = 0;
		while(en == 0&& k<15){
			k++;
			cf = (k+1)/2, cb = k/2;
            unordered_map<string, int> m;
            vis = m;
			dfs_forward(0, be, ix, iy);
			dfs_backward(0, ed, 2, 2);
		}
		en ? cout<<k<<endl : cout<<-1<<endl;
	}
	return 0;
}
