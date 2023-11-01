#include<bits/stdc++.h>
using namespace std;
// Åö×²£¬ sizeÈ¡ËØÊı
const int N = 10000000 + 5;
int prim[N], p[N], c, m, n, ha[N];
void findPrim(int n){
	p[1]=1;
	for(int i = 2; i <= n; i++)
		if(p[i]==0){
			prim[c++]=i;
			for(int j = i+i; j <= n; j+=i) p[j]=1;
		}
} 

int main(){
	findPrim(N);
	scanf("%d%d", &m, &n);
	if(p[m]==1)
		for(int i = m+1; i < N; i++)
			if(p[i]==0){
				m = i;
				break;
			}
	for(int i = 0; i < n; i++){
		int t; scanf("%d", &t);
		int k = t % m;
		if(ha[k]==0){
			ha[k]++;
			if(i != 0) printf(" ");
			printf("%d", k);
		}else{
			int j;
			for(j = 1; j < n; j++)
				if(ha[ (k + j*j)%m ] == 0){
					ha[ (k + j*j)%m ]++;
					printf(" %d", (k + j*j)%m);
					break;
				}
			if(j == n) printf(" -");
		}
	}
	return 0;
}
