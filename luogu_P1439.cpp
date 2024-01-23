#include<bits/stdc++.h>
using namespace std;

int n, a[100000+5], b[100000+5], mp[100000+5], l[100000+5], c;

int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		b[i] = mp[b[i]];
	}	
	l[++c] = b[1];
	for(int i = 2; i <= n; i++){
		if(b[i] >= l[c]){
			l[++c] = b[i];
		}else{
			int lo = 1, hi = c+1;
			while(lo < hi){
				int mi = (lo + hi)>>1;
				if(l[mi] >= b[i] ){
					hi = mi;
				}else{
					lo = mi + 1;
				}
			}
			l[lo] = b[i];
		}
	}
	printf("%d\n", c);
	return 0;
}
