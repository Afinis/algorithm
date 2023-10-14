#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
map<char, int> m;
char a[N], b[N];

int main(){
	//scanf("%s%s", a, b);
	fgets(a, N, stdin);
	fgets(b, N, stdin);
	int l = strlen(a);
	for(int i = 0; i < l; i++){
		m[a[i]]++;
		if('A' <= a[i] && a[i] <= 'Z')
			m[a[i] - ('A'-'a') ]++;
	}
	l = strlen(b);
	int c = 0;
	for(int i = 0; i < l; i++){
		if(m.count(b[i]) || (m.count('+') && 'A' <= b[i] && b[i] <= 'Z') ){
			c++;
			continue;
		}
		printf("%c", b[i]);
	}
	printf("\n");
	return 0;
}
