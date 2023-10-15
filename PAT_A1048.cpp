#include <bits/stdc++.h>
using namespace std;
int e[100000+5];
map<int, int> m;
int main(){
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &e[i]);
		m[e[i]]++;
	}
	sort(e, e+n);
	int c = 0;
	for(int i = 0; i < n; i++)
		if( p-e[i] == e[i]){
			if(m[p-e[i]] > 1){
				c++;
				printf("%d %d", e[i], p-e[i]);
				break;
			}
		}else if(m[p-e[i]]){
			c++;
			printf("%d %d", e[i], p-e[i]);
			break;
		}
	if(c==0) printf("No Solution");
	return 0;
}
