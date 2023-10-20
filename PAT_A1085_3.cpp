#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p, e[100000+5];
int main(){
	scanf("%lld%lld", &n, &p);
	for(int i = 0; i < n; i++) scanf("%lld", &e[i]);
	sort(e, e+n);
	int r = 0;
	int i = 0, j = 0;
	while(i < n && j < n){
		while(j < n && e[j] <= e[i]*p){
			r=max(r, j-i+1);
			j++;
		}
		i++;
	}
	printf("%d", r);
	return 0;
}
