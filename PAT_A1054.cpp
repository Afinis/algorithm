#include<bits/stdc++.h>
using namespace std;
map<int , int> c;
int main(){
	int n, m; scanf("%d%d",&n, &m);
	while(m-- ){
		int t = n;
		while(t--){
			int e; scanf("%d", &e);
			c[e]++;
		}
	}
	int k, ma=0;
	for(auto it = c.begin(); it != c.end(); it++)
		if(ma < it->second){
			ma = it->second;
			k = it->first;
		}
	printf("%d", k);
	return 0;
}
