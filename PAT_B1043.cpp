#include<bits/stdc++.h>
using namespace std;
const int N = 10000+5;
char s[N];
map<char, int> m;
int main(){
	fgets(s, N, stdin);
	int l = strlen(s);
	for(int i = 0; i < l; i++) m[s[i]]++;
	char d[] = "PATest";
	l = strlen(d);
	while(1){
		int c = 0;
		for(int i = 0; i <l; i++)
			if(m[d[i]]){
				c++;
				printf("%c", d[i]);
				m[d[i]]--;
			}
		if(c==0) break;
	}
	return 0;
}
