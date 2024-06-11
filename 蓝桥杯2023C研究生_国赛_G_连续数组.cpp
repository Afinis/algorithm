#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n, op[N], vis[N], a[N], ans;

void dfs(int k){
	if(k == n){
		ans++;
	/*	for(int i = 0; i < n; i++){
			cout<<a[i]<<" ";			
		}
		cout<<endl;
	*/
		return;
	}
	
	if(k-1>=0 && op[k-1]==1 ){
		if(a[k-1]+1 <= n && !vis[a[k-1]+1]){
			a[k] = a[k-1]+1;
			vis[a[k-1]+1] = 1;
			dfs(k+1);
			vis[a[k-1]+1] = 0;
		}
		return;
	}

	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		if(k-1>=0 && op[k-1]==0 && i==a[k-1]+1) continue;
		a[k] = i;
		vis[i] = 1;
		dfs(k+1);
		vis[i] = 0;
	}
}

int main(){
	cin>>n;
	for(int i = 0; i < n-1; i++){
		cin>>op[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
