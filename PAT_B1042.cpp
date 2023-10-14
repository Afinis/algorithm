#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N];
map<char, int> m;
int main(){
	fgets(s, N, stdin);
	int l = strlen(s);
	for(int i = 0 ; i < l; i++)
		if(s[i] != ' ')
			if('A' <= s[i] && s[i] <= 'Z') m[s[i]-('A'-'a')]++;
			else if('a' <= s[i] && s[i] <= 'z') m[s[i]]++;
	char a = 'a';
	int r = 0;
	for(auto it = m.begin(); it != m.end(); it++){
		char b = it->first;
		int c = it->second;
		if(r < c){
			r = c;
			a = b;
		}else if(r==c && a > b) a = b;	
	}
	printf("%c %d", a, r);
	return 0;
}
