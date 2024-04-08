#include<bits/stdc++.h>
using namespace std;
int n, vmin, vmax=1e9+10;

int main(){
	cin>>n;
	int a, b;
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		vmax = min(vmax, a/b);
		vmin = max(vmin, a/(b+1)+1);
	} 
	cout<<vmin<<" "<<vmax<<endl;
	return 0;
}
