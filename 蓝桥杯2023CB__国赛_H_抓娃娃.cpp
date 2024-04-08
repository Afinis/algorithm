#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m;
int mp[N];
int main(){
	cin>>n>>m;
	int l,r;
	for (int i=1;i<=n;i++){
		cin>>l>>r;
		mp[l+r]++;//标记中点
	}
	for (int i=1;i<N;i++){
		mp[i]+=mp[i-1];//前缀和预处理
	}
	for (int i=1;i<=m;i++){
		cin>>l>>r;
		l*=2;
		r*=2;
		cout<<mp[r]-mp[l-1]<<endl;
	}
	return 0;
}
