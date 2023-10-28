#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

int n,m,e[100+5];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &e[i]);
	m = m%n;
	int d = gcd(m, n);
	for(int i = n-m; i < n-m+d && i < n; i++){
		int t = e[i], p = i, ne;
		while((ne = (p - m + n)%n) != i){
			e[p] = e[ne];
			p = ne;
		}
		e[p] = t;
	}
	for(int i = 0; i < n; i++){
		if(i != 0) printf(" ");
		printf("%d", e[i]);
	}
	return 0;
}
