#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int n,c;
int a[N], l[N], r[N], ans[N];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++) l[i] = max(a[i-1], l[i-1]);
	r[n-1] = (1<<31)-1;
	for(int i = n-2; i >= 0; i--) r[i] = min(a[i+1], r[i+1]);
	for(int i = 0; i < n; i++)
		if(l[i] < a[i] && a[i] < r[i]) ans[c++] = a[i];
	printf("%d\n", c);
	for(int i = 0; i < c; i++){
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
