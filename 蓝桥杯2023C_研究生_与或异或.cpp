#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10;
ll a[15][15], op[15], ans, c[]={0, 0, 4, 7, 9}, cnt, cnt2; 

bool check(){
	for(int i = 1; i < 5; i++){
		for(int j = 0; j < 5-i; j++){
			if(op[c[i]+j] == 0)
				a[i][j] = a[i-1][j] & a[i-1][j+1];
			else if(op[c[i]+j] == 1)
				a[i][j] = a[i-1][j] | a[i-1][j+1];
			else if(op[c[i]+j] == 2)
				a[i][j] = a[i-1][j] ^ a[i-1][j+1];
		}
	}
	return a[4][0] == 1;
}

void dfs(ll i){
	if(i==N){
		cnt++;
		if(check()){
			ans++;
		}else{
			cnt2++;
		}
		return;
	}
	for(ll j = 0; j < 3; j++){
		op[i] = j;
		dfs(i+1);
	}
}

int main(){
	a[0][0]=1, a[0][1]=0, a[0][2]=1, a[0][3]=0, a[0][4]=1;
	dfs(0);
	cout<<ans<<endl; // 30528
	cout<<cnt<<endl;
	cout<<cnt2<<endl;
	return 0;
}
