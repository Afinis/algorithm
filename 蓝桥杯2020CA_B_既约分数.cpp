#include<bits/stdc++.h>
using namespace std;
int n = 2020, ans=0;
int gcd(int a, int b){
	return a == 0 ? b : gcd(b%a, a);
}

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(gcd(i, j)==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
