#include<bits/stdc++.h>
using namespace std;
int n = 45, g[1000][1000], c;

int main(){
	for(int i = 2; i <= n+1; i++)
		for(int j = 1; j < i; j++)
			if(i%2==0) g[i-j][j] = ++c;
			else g[j][i-j] = ++c;
	cout<<g[20][20]<<endl;
	return 0;
}
