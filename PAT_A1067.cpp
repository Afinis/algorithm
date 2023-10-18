#include <bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int e[N], c, n, r, p[N]; 

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", e+i);
		p[e[i]] = i;
		if(e[i] != 0 && e[i] == i) c++;
	}
	int ne = 1;
	while(c != n-1)
		if(p[0] != 0){
			swap(p[0], p[p[0]]);
			c++;
			r++;
		}else
			while(ne < n){
				if(p[ne] != ne){
					swap(p[0], p[ne]);
					r++;
					break;
				}
				ne++;
			}
	printf("%d", r);
	return 0;
}
