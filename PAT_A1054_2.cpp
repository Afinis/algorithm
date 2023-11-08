#include<bits/stdc++.h>
using namespace std;
int n, m, c = 0, k;
int main(){
	scanf("%d%d",&n, &m);
	while(m-- ){
		int t = n;
		while(t--){
			int e; scanf("%d", &e);
			if(c == 0) k = e;
			else k == e ? c++ : c--;
		}
	}
	printf("%d", k);
	return 0;
}
