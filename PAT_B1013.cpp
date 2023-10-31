#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5, inf = (1<<31)-1, M = N*10;
int p[M], prim[N], c=1;

int main(){
	int lo,hi; cin>>lo>>hi;
	for(int i = 2; c <= hi; i++){
		if(p[i]==0){
			prim[c++] = i;
			for(int j = i+i; j < M; j+=i){
				p[j]=1;
			}
		}
	}
	int l = 0;
	for(int i = lo; i <= hi; i++){
		printf("%d" , prim[i]);
		if(++l %10 == 0) printf("\n");
		else if(i!= hi) printf(" ");
	} 
	return 0;
}
