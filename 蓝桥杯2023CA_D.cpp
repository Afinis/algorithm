#include<bits/stdc++.h>
using namespace std;
int dp[5000+10];
char e[5000+10];
bool mycmp(char* a, int l){
	for(int i = 0; i < l; i++){
		if(a[i] > a[l-1-i])
			return true;
		else if(a[i] < a[l-1-i])
			return false;	
	}
	return false;
}
int main(){
	scanf("%s", e);
	int l = strlen(e);
	for(int i = 0; i < l; i++){
		int c = 0;
		for(int j = i-1; j >= 0; j--){
			if(mycmp(e+j, i-j+1))
				c++;
		}
		dp[i+1] = dp[i] + c;
	}
	cout<<dp[l]<<endl;
	return 0;
}
