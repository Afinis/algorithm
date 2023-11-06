#include<bits/stdc++.h>
using namespace std;

map<string, vector<int> > m; 
int n,k;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++){
		int id, t; scanf("%d%d", &id, &t);
		for(int j = 0; j < t; j++){
			char s[10]; scanf("%s", s);
			string stu = string(s);
			m[stu].push_back(id);
		}
	}	
	for(int i = 0; i < n; i++){
		char s[10]; scanf("%s", s);
		string stu = string(s);
		printf("%s %d", s, m[stu].size());
		sort(m[stu].begin(), m[stu].end());
		for(int j = 0; j < m[stu].size(); j++){
			printf(" %d", m[stu][j]);
		}
		printf("\n");
	}
	return 0;
}
