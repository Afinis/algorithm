#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, m, a[N], b[N], c;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	
	for(int i=0, j=0; i<n&&j<m; i++, j++){
		if(a[i]==b[j]){
			continue;
		}
		if(a[i] < b[j]){
			a[i+1] = a[i] + a[i+1];
			a[i] = 0;
			j--;
			c++;
		}else{
			b[j+1] = b[j] + b[j+1];
			b[j] = 0;
			i--;
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
