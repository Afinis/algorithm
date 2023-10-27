#include<bits/stdc++.h>
using namespace std;
long double t, r=0;
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%Lf", &t);
		r += t*i*(n+1-i);
	}
	printf("%.2Lf\n", r);
	return 0;
}
