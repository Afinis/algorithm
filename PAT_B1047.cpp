#include<bits/stdc++.h>
using namespace std;

map<int, int> m;
int main(){
	int n;
	scanf("%d", &n);
	for(int i= 0; i < n; i++){
		int a,b,c;
		scanf("%d-%d %d", &a,&b,&c);
		m[a] += c;
	}
	int a, ma=0;
	for(auto it = m.begin(); it!=m.end(); it++){
		if(it->second > ma){
			ma = it->second;
			a = it->first;
		}
	}
	printf("%d %d", a, ma);
	return 0;
}
