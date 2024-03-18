#include<bits/stdc++.h>
using namespace std;
long long n, t, x=1;
char s[10005];

int main(){
	scanf("%lld%lld", &n, &t);
	scanf("%s", s);
	while(x < n) x <<= 1;
	t = t%x;
	for(int i = 0; i < t; i++){
		for(int j = n-1; j >= 1; j--){
			s[j]=(s[j]-'0')^(s[j-1]-'0')+'0';
		}
	}
	printf ("%s\n",s);
	return 0;
}
