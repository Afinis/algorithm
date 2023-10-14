#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
map<int, int> m;
char a[N], b[N];

int main(){
	//scanf("%s%s", &a, &b);
	fgets(a, N, stdin);
	fgets(b, N, stdin);
	int la = strlen(a), lb = strlen(b);
	for(int i = 0; i < la; i++)
		m[a[i]]++;
	int c = 0;
	for(int i = 0; i < lb; i++)
		m[b[i]] == 0 ? c++ : m[b[i]]--;
	c ? printf("No %d", c): printf("Yes %d", la-lb);
	return 0;
}
