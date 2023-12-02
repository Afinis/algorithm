#include<bits/stdc++.h>
using namespace std;

int a[70], n, vis[70], vc=1, r, ma, nei[70];
bool dfs(int in, int sum){
	if(sum == r){
		sum = 0;
		in = 0;
	}
	if(vc == n && sum == 0) return true;
	bool en = false;
	for(int i = in+1; i < n; i++){
		if(vis[i] == 0){
			if(sum + a[i] <= r){
				vis[i] = 1;
				vc++;
				if(en == false) en = dfs(i, sum+a[i]);
				else break;
				vis[i] = 0;
				vc--;
			}
 			if(en) return true;
 			if(r - sum == a[i] || sum == 0) return false;
			i = nei[i]-1;
		}
	}
	return en;
}


int main(){
	cin>>n;
	int su = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		ma = max(a[i], ma);
		su += a[i];
	}
	sort(a, a+n, greater<int>());
	int pre = 0, ne;
	for(int i = 0; i < n; i++)
		if(a[pre] != a[i])
			while(pre < i) nei[pre++] = i;
	while(pre < n) nei[pre++] = n;
	int l = n;
	vis[0] = 1;
	for(int i = ma; i <= su; i++){
		if(su % i == 0){
			r = i;
			if(dfs(0, a[0])){
				cout<<r<<endl;
				return 0;
			}
		}
	}
	return 0;
}
