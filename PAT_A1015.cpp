#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int p[N], prim[N], c, d[111], dl;
void findPrim(int n){
	for(int i = 2; i <= n; i++)
		if(p[i]==0){
			prim[c++]=i;
			for(int j = i+i; j <= n; j+=i)p[j]=1;
		}
}

int reverRadix(int n, int r){
	dl=0;
	while(n){
		d[dl++] = n%r;
		n /= r;
	}
	for(int i = 0; i < dl; i++)
		n = n*r + d[i];
	return n;
}

int main(){
	findPrim(N);
	p[1] = 1; 
	while(1){
		int n, d;
		scanf("%d", &n);
		if(n < 0) return 0;
		scanf("%d", &d);
		if(p[n]) printf("No\n");
		else if(p[reverRadix(n, d)]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
