#include<bits/stdc++.h>
using namespace std;
int n, m; 
double w[100000+10], dp[100000+10];
struct node{
	vector<int> ind, outd;
};
unordered_map<int, node> no;
unordered_map<int, int> g[100000+10];

void DFS(int i){
	if(i == 1){
		w[i] = 1 / (double)no[i].outd.size();
	}else{
		for(int j = 0; j < no[i].ind.size(); j++){
			int son = no[i].ind[j];
			if(w[son] == 0) DFS(son);
			w[i] += w[son];
		}
		w[i] = w[i] / (double)no[i].outd.size();
	}
	for(int j = 0; j < no[i].ind.size(); j++){
		int son = no[i].ind[j];
		dp[i] += w[son]*g[son][i] + dp[son]/(double)no[son].outd.size() ;
	}
//	printf("dp[%d]=%.2f\n", i, dp[i]);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(no.count(u)==0){
			node t;
			t.outd.push_back(v);
			no[u] = t;
		}else no[u].outd.push_back(v);
		if(no.count(v)==0){
			node p;
			p.ind.push_back(u);
			no[v] = p;
		}else no[v].ind.push_back(u);
		g[u][v] = w;
	} 
	DFS(n);
	printf("%.2f\n", dp[n]);
	return 0;
}
