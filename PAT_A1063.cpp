#include<bits/stdc++.h>
using namespace std;


set<int> se[60];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int m; scanf("%d", &m);
		for(int j = 0; j < m; j++){
			int t; scanf("%d", &t);
			se[i].insert(t);
		}
	}
	int k; scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int a,b, in = 0; scanf("%d%d", &a, &b);
		//³¬Ê±Ğ´·¨ 
		//set<int> inter,un;
		//set_intersection(se[a].begin(), se[a].end(), se[b].begin(), se[b].end(), inserter(inter, inter.begin()));
		//set_union(se[a].begin(), se[a].end(), se[b].begin(), se[b].end(), inserter(un, un.begin()));
		//printf("%.1f%\n", inter.size()/(double)un.size()*100);
		for(auto it = se[a].begin(); it != se[a].end(); it++){
			if(se[b].count(*it)){
				in++;
			}
		}
		printf("%.1f%%\n", in/(double)(se[a].size() + se[b].size() - in)*100);
	}
	return 0;
}
