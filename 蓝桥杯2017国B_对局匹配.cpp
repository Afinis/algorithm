#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k, a[N], c[N], ma, ans; 

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[a[i]]++;
		ma = max(ma, a[i]);
	}
	if(k==0){
		for(int i = 0; i <= ma; i++){
			if(c[i]) ans++;
		}
		printf("%d", ans);
		return 0;
	}
	for(int i = 0; i+k <= ma; i++){
		if(c[i] < c[i+k]) 
			c[i+k] -= c[i];
		else c[i+k] = 0;
	}
	for(int i = 0; i <= ma; i++)
		ans += c[i];
	
	printf("%d", ans);
	return 0;
}
