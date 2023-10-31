#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int p[N], prim[N], c;



int main(){
	int n; cin>>n;
	for(int i = 2; i<=n; i++){
		if(p[i]==0){
			prim[c++] = i;
			for(int j = i+i; j <= n; j+=i){
				p[j]=1;
			}
		}
	}
	int r = 0;
	for(int i = 0; i < c-1; i++){
		if(prim[i+1]-prim[i]==2) r++;
	} 
	printf("%d" , r);
	return 0;
}
