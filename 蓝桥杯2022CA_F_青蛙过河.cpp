#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000+5;
int n, x, h[MAX], s[MAX], lo, hi = MAX;

bool check(int l){
	for(int i = l; i < n; i++)
		if(s[i]-s[i-l] < x)
			return false;
	return true;
}

int main(){
	scanf("%d%d", &n, &x);
	x <<= 1;
	for(int i = 1; i < n; i++){
		scanf("%d", &h[i]);
		s[i] += h[i] + s[i-1];
	}
	while(lo < hi){
		int mi = (lo+hi)>>1;
		if(check(mi))
			hi = mi;
		else
			lo = mi+1;	
	}
	printf("%d\n", hi);
	return 0;
}
