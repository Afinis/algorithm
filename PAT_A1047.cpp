#include<bits/stdc++.h>
using namespace std;

map<int, vector<string> > m; 
int n,k;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		char s[10]; int c; scanf("%s%d", s, &c);
		string stu = string(s);
		for(int j = 0; j < c; j++){
			int t; scanf("%d", &t);
			m[t].push_back(stu);
		}
	}
	for(int i = 1; i <= k; i++){
		printf("%d %d\n", i, m[i].size());
		sort(m[i].begin(), m[i].end());
		for(int j = 0; j < m[i].size(); j++){
			printf("%s\n", m[i][j].c_str());
		}
	}
	return 0;
}
