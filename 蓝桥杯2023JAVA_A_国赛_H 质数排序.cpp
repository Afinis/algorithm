#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n, a[N], P[N], mp[N], b[N], p[N];
long long m = 998244353, ans;
bool cmp(int a, int b){
	int ia = mp[a], ib = mp[b];
	if(P[ia] && P[ib]){
		return a < b;
	}
	return false;
}

int main(){
	cin>>n;
	P[2] = P[3] = P[5] = P[7] = 1;
	p[0]=2, p[1] = 3, p[2] = 5, p[3] = 7;
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
	
	do{
		for(int i = 1; i <= n; i++){
			b[i] = a[i];
		}
		for(int i = 0; i < 3 && p[i] <= n; i++){
			int mi = b[p[i]], id = i;
			for(int j = i+1; j < 4 && p[j] <= n; j++){
				if(mi > b[p[j]]){
					mi = b[p[j]];
					id = j;
				}
			}
			swap(b[p[i]], b[p[id]]);
		}
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(b[i] > b[j]){
					ans++;
					ans %= m;
				}
			}
		}
	}while(next_permutation(a+1, a+n+1));
	cout<<ans<<endl;
	return 0;
}
