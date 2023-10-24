#include<bits/stdc++.h>
using namespace std;
const int N = 200000+5, inf = (1<<31)-1;
int n, m, a[N], b[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	a[n] = inf; // Ä©Î²Ìí¼ÓÉÚ±ø½Úµã 
	scanf("%d", &m);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);
	b[m] = inf;
	int mi = (n+m-1)/2, i = 0, j = 0;
	while(i+j < mi)	
		a[i] < b[j] ? i++ : j++;
	printf("%d", a[i] < b[j] ? a[i] : b[j]); 
	return 0;
}
