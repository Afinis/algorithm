#include<bits/stdc++.h>
using namespace std;
const int N = 2020;
int notP[2*N], p[N*2], pc, ans, c;

void init(){
	notP[1] = 1;
	for(int i = 2; i <= N; i++){
		if(!notP[i]){
			p[pc++] = i;
		}
		for(int j = 0; j < pc && p[j]*i<= N; j++){
			notP[p[j]*i]++;
			if(i%p[j]==0) break;
		}
	}
}

int main(){
	init();
	ans = N-pc-1;
	cout<<ans<<endl; // 1713
	return 0;
}
