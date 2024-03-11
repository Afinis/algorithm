#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000000], c[1000000];

int lowbit(int x){
	return x & -x;
}

void add(int x, int k){
	while(x <= n){
		c[x]+=k;
		x = x + lowbit(x);
	}
}

int getSum(int x){
	int ans = 0;
	while(x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d", &t);
		add(i, t);
	}
	for(int i = 0; i < m; i++){
		int a, x ,y;
		scanf("%d%d%d", &a, &x, &y);
		if(a==1) add(x, y);
		else printf("%d\n", getSum(y)-getSum(x-1));
	}	
	return 0;
}
