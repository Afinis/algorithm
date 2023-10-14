#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, k;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int key;
		scanf("%d", &key);
		m[key]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int key;
		scanf("%d", &key);
		if(i!=0) printf(" ");
		printf("%d", m[key]);
	}
	return 0;
}
