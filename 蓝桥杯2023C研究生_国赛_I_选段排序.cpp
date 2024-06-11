#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n, p, q, a[N], b[N], ans;


int main(){
	scanf("%d%d%d", &n, &p, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			sort(b+i, b+j+1);
			ans = max(b[q] - b[p], ans);
			
			for(int k = i; k <= j; k++){
				b[k] = a[k];
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
