#include<bits/stdc++.h>
using namespace std;

int a[30], vis[1005], ans=0;

// pred: [now, 100] 中最理想的情况下能保留几个数 
void dfs(int now, int cnt, int pred){
	if(cnt+pred <= ans) return;
	if(cnt > ans) ans = cnt;
	if(now == 100) return;	
	
	if(!vis[now]){
		int t[20], tc=0;
		for(int i = 1; i <= 15; i++){ 
			// 枚举比now大的数
			if(a[i]-now <= 0) continue;
			if(a[i]-now == now) continue;
			if(a[i]-now > 100) break;
			if(!vis[a[i]-now]){
				vis[a[i]-now]=1;
				t[tc++] = a[i]-now;
			}
		}
		dfs(now+1, cnt+1, pred-tc-1);
		for(int i = 0; i < tc; i++){
			vis[t[i]]=0;
		}
	}
	if(!vis[now]){
		vis[now]=1;
		dfs(now+1, cnt, pred-1);
		vis[now]=0;
	}else
		dfs(now+1, cnt, pred);
}

int main(){
	int pred = 100; 
	for(int i = 1; i <= 15; i++){
		a[i] = i*i;
		vis[a[i]] = 1;
		if(a[i] <= 100) pred--;
	}
	dfs(2, 0, pred);
	cout<<ans<<endl;
	return 0;
}
