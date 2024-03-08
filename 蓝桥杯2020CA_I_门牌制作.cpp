#include<bits/stdc++.h>
using namespace std;
int n = 2020, ans;
int main(){
	for(int i = 1; i <= n; i++){
		int x = i;
		while(x){
			if(x%10==2) ans++;
			x/=10;
		}
	}
	printf("%d", ans);
	return 0;
}
