#include<bits/stdc++.h>
using namespace std;
const int N =100000 + 5;
int c[N], p[N];
long long r;
int main(){
	int nc, np;
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++){
		scanf("%d", &c[i]);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; i++){
		scanf("%d", &p[i]);
	}
	sort(c, c+nc, greater<int>());
	sort(p, p+np, greater<int>());
	for(int i = 0; i < nc && i < np; i++){
		if(c[i] <= 0 || p[i] <= 0) break;
		r += c[i]*(long long)p[i];
	}
	int i = nc-1, j=np-1;
	while(i>=0 && j>=0){
		if(c[i] >= 0 || p[j] >= 0) break;
		r += c[i]*(long long)p[j];
		i--;
		j--;
	}
	printf("%lld", r);
	return 0;
}
