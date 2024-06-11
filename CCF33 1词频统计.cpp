#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int txt[N][N], a[N], b[N]; 

int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int l; cin>>l;
		for(int j = 0; j < l; j++){
			int t; cin>>t;
			txt[i][t]++;
			b[t]++; 
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(txt[i][j]){
				a[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<a[i]<<" "<<b[i]<<endl;
	}
	return 0;
}
