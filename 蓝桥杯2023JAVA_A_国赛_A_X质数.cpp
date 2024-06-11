#include<bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 2e6;
int p[M], pc, notP[M], d[10], ans;
void init(){
	notP[1] = 1;
	for(int i = 2; i <= N; i++){
		if(notP[i]==0){
			p[pc++] = i;
			for(int j = i*2; j <= N; j+= i){
				notP[j] = 1;
			}
		}
	}
}
int a, l;
bool dfs(int x, int p){
	if(p==l){
		if(x && notP[x]==0){
			return true;
		}
		return false;
	}
	if(dfs(x*10+ (a/(d[p]))%10, p+1 ) || dfs(x, p+1))
		return true;
	
	return false;
}

int leng(int x){
	int r = 0;
	while(x){
		r++;
		x /= 10;
	}
	return r;
}
int main(){
	init();
	d[0] = 1;
	for(int i = 1; i < 6; i++){
		d[i] = d[i-1]*10;
	}
	for(int i = 2; i < N; i++){
		a = i; l = leng(a);
		if(dfs(0, 0)) ans++;	
	}
	cout<<ans<<endl;  // 989457
	return 0;
}
