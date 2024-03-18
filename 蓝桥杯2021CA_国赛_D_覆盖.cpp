#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 8;
ll ans = 0, vis[10][10];
void dfs(int x, int y){
	if(x==n && y==n && vis[x][y]){
		ans++;
	}
	if(vis[x][y]){
		if(y < n){		
			dfs(x, y+1);
		}else if(x < n){
			dfs(x+1, 1);
		}
	}else{
		vis[x][y]=1; 
		if(y < n && vis[x][y+1]==0){
			vis[x][y+1]=1;
			dfs(x, y+1);
			vis[x][y+1]=0;
		}
		if(x < n && vis[x+1][y]==0){
			vis[x+1][y]=1;
			if(y < n) dfs(x, y+1);
			else dfs(x+1, 1);
			vis[x+1][y]=0;
		}
		vis[x][y]=0; 
	}
} 


int main(){
	dfs(1, 1);
	cout<<ans<<endl;
	
	return 0;
}
