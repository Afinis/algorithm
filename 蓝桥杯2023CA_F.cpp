#include <bits/stdc++.h>
using namespace std;
int n, m, mi, ans = 1000;
unordered_map<int, int> c1;
int w[35];

void dfs(int i, int r, int c, bool first){
	if(r > m || c > ans) return;
	if(r == m){
		ans = min(ans, c);
		return;
	}
	if(i == mi && first){
		if(c1.count(r))
			c1[r] = min(c1[r], c);
		else
			c1[r] = c;	
		return;
	}
	if(i == n && !first){
		if(c1.count(m-r))
			ans = min(ans, c1[m-r] + c);
		return;
	}
	dfs(i+1, r, c, first);
	dfs(i+1, r+(w[i]>>1), c+1, first);
	dfs(i+1, r+w[i], c, first);
} 

int main(){
	scanf("%d%d", &n, &m);
	m = m << 1;
	mi = n/2;
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
		w[i] = w[i] << 1;
	}
	sort(w, w+n);
	dfs(0, 0, 0, true);
	dfs(mi, 0, 0, false);
	
	if(ans == 1000){
		printf("-1\n");
	}else
		printf("%d\n", ans);
	return 0;
}
