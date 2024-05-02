#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int n, m, x, a[N], R[N];
unordered_map<int , int> id;

int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	fill(R, R+N, N);
	for(int i = 1; i <= n; i++){
		int t = a[i]^x;
		if(id[t]){
			R[id[t]] = min(i, R[id[t]]);
		}
		id[a[i]] = i;
	}
	for(int i = n; i >= 1; i--){
		R[i] = min(R[i+1], R[i]);	
	}
	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);
		if(R[l] && R[l] <= r){
			printf("yes\n");
		}else printf("no\n");
	}
	return 0;
}
