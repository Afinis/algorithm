#include <bits/stdc++.h>
using namespace std;
const int N = 10000+5;
char a[N], b[N];
map<char, int> m;
int main(){
	fgets(a, N, stdin);
	fgets(b, N, stdin);
	int l = strlen(b);
	for(int i = 0; i < l; i++)
		m[b[i]]++;
	l = strlen(a);
	for(int i = 0; i < l; i++){
		if(m[a[i]]) continue;
		printf("%c", a[i]);
	}
	return 0;
}
