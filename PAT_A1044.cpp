#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int n,m, e[N], s[N], p=N;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", e+i);
		s[i] = s[i-1] + e[i];
	}
	for(int i = 1; i <= n; i++){
		int j = lower_bound(s, s+n+1, m+s[i-1])-s;
		if(s[j] - s[i-1] == m){
			p = m;
			break;
		}else if(j <= n && s[j] - s[i-1] < p)
			p = s[j] - s[i-1];
	}
	for(int i = 1; i <= n; i++){
		int j = lower_bound(s, s+n+1, p+s[i-1])-s;
		if(s[j] - s[i-1] == p) printf("%d-%d\n",i, j);
	}
	return 0;
}

