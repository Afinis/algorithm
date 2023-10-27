#include<bits/stdc++.h>
using namespace std;
int n, r, now, ne;
int main(){
	scanf("%d", &n);
	for(int i = 0 ;i < n; i++){
		scanf("%d", &ne);
		now < ne ? r += (ne-now)*6 : r += (now-ne)*4;
		now = ne;
	}
	printf("%d", r+5*n);
	return 0;
}
