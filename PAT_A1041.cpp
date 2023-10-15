#include <bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int num[N], l;
map<int, int> m;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", num+i);
		l++;
		m[num[i]]++;
	}
	int c = 0;
	for(int i = 0; i < l; i++)
		if(m[num[i]] == 1){
			printf("%d", num[i]);
			c++;
			break;
		}
	if(c==0) printf("None");
	return 0;
}
