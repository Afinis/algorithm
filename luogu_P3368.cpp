#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000000], c[1000000];

int lowbit(int x){
	return x & -x;
}

void add(int x, int k){
	while(x<=n){
		c[x]+=k;
		x += lowbit(x);
	}
}

int getSumC(int x){
	int ans = 0;
	while(x){
		ans+=c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		int t = a[i] - a[i-1];
		add(i, t);
	}
	for(int i = 0; i < m; i++){
		int a, x ,y;
		scanf("%d", &a);
		if(a==1){
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			add(x, k);
			add(y+1, -k); 
		}else{
			int t;
			scanf("%d", &t);
			printf("%d\n", getSumC(t));
		}
	}	
	return 0;
}
