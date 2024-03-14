#include<bits/stdc++.h>
using namespace std;
const int M = 1e6;
int p[M+100], notP[M+100], pc, n, ans=M, f[M+100];
void Euler(){
	
	for(int i = 2; i <= n; i++){
		if(!notP[i]){
			p[pc++] = i;
			f[i] = i;
		}
		for(int j = 0; j<pc && p[j]*i<=n; j++){
			notP[p[j]*i] = 1;
			f[p[j]*i] = max(f[i], p[j]);
			if(i%p[j]==0) break;
		}
	} 
}

int main(){
	cin>>n;
	Euler();
	if(!notP[n]){
		cout<<-1<<endl;
		return 0;
	}
	for(int x2 = n-f[n]+1; x2 <= n; x2++){
		if(!notP[x2]) continue;
		ans = min(ans, x2-f[x2]+1);
	}
	if(ans==M) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
