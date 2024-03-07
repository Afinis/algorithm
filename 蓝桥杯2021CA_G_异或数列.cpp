#include<bits/stdc++.h>
using namespace std;

int t, x[2*100000+5], n;
int main(){
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		int r = 0, p = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &x[j]);
			r ^= x[j];
		}
		if(r==0){
			printf("0\n");
			continue;
		}
		for(int j = 0; r; j++){
			if(r&1) p = j;
			r >>= 1;
		}
		int c1 = 0, c0 = 0;
		for(int j = 0; j < n; j++){
			if(x[j]&(1<<p)) c1++;
			else c0++; 
		}
		if(c1==1 || c0%2==0) printf("1\n");
		else printf("-1\n");
	}
	return 0;
}
