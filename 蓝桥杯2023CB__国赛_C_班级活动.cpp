#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N], n, c[N], x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	for(int i = 1; i <= n; i++){
		if(c[i] > 2){
			x += c[i] - 2;
		}else if(c[i] == 1){
			y++;
		}
	}
	int ans = x+(y-x)/2;
	if((y-x)<0) ans = x;
	printf("%d", ans);
	return 0;
}
