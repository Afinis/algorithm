#include<bits/stdc++.h>
using namespace std;
const int n = 20210605;
int notP[n*2], p[n*2], c, ans;

void Euler(){
	notP[0] = notP[1] = 1;
	for(int i = 2; i <= n; i++){
		if(notP[i]==0)
			p[c++] = i;
		for(int j = 0; j < c && p[j]*i<=n; j++){
			notP[p[j]*i] = 1;
			if(i%p[j]==0) break;	
		}
	}
}

bool check(int i){
	while(i){
		if(notP[i%10]){
			return false;
		}
		i /= 10;
	}
	return true;
}

int main(){
	Euler();
	for(int i = 0; i < c; i++){
		if(check(p[i])){
			if(ans <= 20) cout<<p[i]<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
