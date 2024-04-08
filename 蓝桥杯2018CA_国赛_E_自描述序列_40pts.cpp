#include<bits/stdc++.h>
using namespace std;

const int N = 1e8; 
int n, a[N],c;

int main(){
	cin>>n;
	a[1] = 1, a[2] = a[3] = 2; c = 2;
	for(int i = 3; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			a[++c] = i;
			if(c>=n){
				cout<<a[n]<<endl;
				return 0;
			}
		}
	}
	cout<<a[n]<<endl;
	return 0;
}
