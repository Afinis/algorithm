#include<bits/stdc++.h>
using namespace std;

int n;
map<vector<int>, int> m; 
void dfs(int sum, vector<int> v ){
	if(sum == n && v.size() != 1){
		sort(v.begin(), v.end());
		m[v]++;
		return;
	}
	for(int i = 1; i <= n-sum; i++){
		v.push_back(i);
		dfs(sum+i, v);
		v.pop_back();
	}
}

int main(){
	cin>>n;
	vector<int> v;
	dfs(0, v);
	for(auto it = m.begin(); it != m.end(); it++){
		auto v = it->first;
		for(int i = 0; i < v.size(); i++){
			if(i != 0) printf("+");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}
