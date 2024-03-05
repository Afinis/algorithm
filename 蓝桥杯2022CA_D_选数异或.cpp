#include<bits/stdc++.h>
using namespace std;
int n, m, x, a[100000+5], lo[100000+5];
unordered_map<int, int> id;
int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(int i = 1; i <= n; i++){		
		lo[i] = max(id[a[i] ^ x], lo[i-1]);	
		id[a[i]] = i;				
	}
	for(int i = 1; i <= m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		if(lo[r] >= l)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
