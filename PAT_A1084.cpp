#include<bits/stdc++.h>
using namespace std;

map<char, int> m, r;

int main(){
	char s[100], d[100];
	scanf("%s%s", s, d);
	for(int i = 0; i < strlen(d); i++){
		m[d[i]] = 1;
	}
	for(int i = 0; i < strlen(s); i++){
		if(!m.count(s[i]) && !r.count(s[i]) ){
			r[s[i]] = 1;
			if('A' <= s[i] && s[i] <= 'Z') r[s[i] - ('A'-'a')] = 1;
			if('a' <= s[i] && s[i] <= 'z'){
				printf("%c", s[i] + ('A'-'a'));
				r[s[i] + ('A'-'a')] = 1;
			}else printf("%c", s[i]);
		}
	}
	return 0;
}
