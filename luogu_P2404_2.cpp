#include<bits/stdc++.h>
using namespace std;

int n, a[100000] = {1};

void dfs(int sum, int c){
	if(sum == n){
		for(int i = 1; i < c; i++){
			if(c==2) continue;
			if(i != 1) printf("+");
			printf("%d", a[i]);
		}
		printf("\n");
		return;
	}
	for(int i = a[c-1]; i <= n-sum; i++){
		if(sum + i <= n){
			a[c] = i;
			dfs(sum + i, c+1);
		}
	}
}

int main(){
	cin>>n;
	dfs(0, 1);
	return 0;
}
