#include<bits/stdc++.h>
using namespace std;
int e[15];
int main(){
	for(int i = 0; i < 10; i++)
		scanf("%d", e+i);
	for(int i = 1; i < 10; i++)
		if(e[i]){
			printf("%d", i);
			e[i]--;
			break;
		}
	while(1){
		int c = 0;
		for(int i = 0; i < 10; i++)
			if(e[i]){
				printf("%d", i);
				e[i]--;
				c++;
				break;
			}
		if(c==0) break;
	}
	return 0;
}
