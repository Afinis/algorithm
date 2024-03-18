#include<bits/stdc++.h>
using namespace std;
const int logn = 20, M = 100000; 
int gcd(int a, int b){
	return a==0? b : gcd(b%a, a);
}
int n, a[M+10], f[2*M+10][logn+5], lg[2*M+10];
void init(){
	for(int i = 2; i < M; i++)
		lg[i] = lg[(i)/2]+1;
	
	for(int j = 1; j < logn; j++){
		for(int i = 1; i+(1<<(j-1)) <= n; i++)
			f[i][j] = gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	}
}

int query(int l, int r){
	int k = lg[r-l+1];
	return gcd(f[l][k], f[r-(1<<k)+1][k]);
}

int main(){
	scanf("%d", &n);
	int c = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i]==1) c++;
		f[i][0] = a[i];
	}
	if(c){
		printf("%d\n", n-c);
		return 0;	
	}
	init();
	int ans=-1;
	for(int r = 1, l=1; r <= n; r++){
		while(l < r && query(l+1, r)==1) l++;
		if(query(l, r)==1)
			ans= ans==-1? r-l : min(ans,r-l);
	}
	if(ans!=-1) ans+=n-1;
	printf("%d\n", ans);
	return 0;
}
