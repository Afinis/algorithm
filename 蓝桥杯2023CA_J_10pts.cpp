#include<bits/stdc++.h>
using namespace std;
const int MAX = 5000000+5;
int n, ans;
int prim[MAX], p[MAX], pc;

int main(){
	cin>>n;
	
	for(int i = 2; i <= n; i++){
		if(p[i]==0){
			ans++;
			prim[pc++] = i;
			for(int j = i+i; j <= n; j+=i){
				p[j] = 1;
			}
		}else{
			int t = 0;
			for(int j = 0; j < pc; j++){
				if(i % prim[j] == 0){
					t++;
				}
			}
			if(t && t%2==0){
				ans++;
			}
		}
	}
	
	cout<<ans+1<<endl;
	return 0;
}
