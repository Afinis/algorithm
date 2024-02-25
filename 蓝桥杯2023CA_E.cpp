#include<bits/stdc++.h>
using namespace std;
const int MAX = 200000+10;
int n; 
int clr[MAX], cnt[2][MAX], node[MAX], dfn, fa[MAX], siz[MAX], big[MAX], L[MAX], R[MAX];
int ans, lo=MAX, hi;
vector<int> son[MAX];

void dfs0(int i){
	L[i] = ++dfn;
	node[dfn] = i;
	siz[i] = 1;
	int bg = 0;
	for(int j = 0; j < son[i].size(); j++){
		int u = son[i][j];
		dfs0(u);
		siz[i] += siz[u];
		if(bg==0 || siz[bg] < siz[u])
			bg = u;
	}
	big[i] = bg;
	R[i] = dfn;			
}

void add(int x){
	cnt[1][cnt[0][x]]--;
	cnt[0][x]++;
	cnt[1][cnt[0][x]]++;
	if(cnt[0][x] < lo) lo = cnt[0][x];
	if(cnt[0][x] > hi) hi = cnt[0][x];
	if(!cnt[1][lo]) lo++;
} 

void del(int x){
	cnt[1][cnt[0][x]]--;
	cnt[0][x]--;
	cnt[1][cnt[0][x]]++;
	if(cnt[0][x] && cnt[0][x] < lo) lo = cnt[0][x];
	if(cnt[0][x] > hi) hi = cnt[0][x];
	if(!cnt[1][hi]) hi--;
} 

void dfs1(int i, bool keep){
	for(int j = 0; j < son[i].size(); j++){
		int u = son[i][j];
		if(u != big[i])
			dfs1(u, false);
	}
	if(big[i])
		dfs1(big[i], true);	
	add(clr[i]);
	for(int j = 0; j < son[i].size(); j++){
		int u = son[i][j];
		if(u != big[i])
			for(int k = L[u]; k <= R[u]; k++){
				int v = node[k];
				add(clr[v]);		
			}
	}
	if(lo == hi) ans++;
	
	if(!keep){
		for(int k = L[i]; k <= R[i]; k++){
			int v = node[k];
			del(clr[v]);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int c, f;
		scanf("%d%d", &c, &f);
		fa[i] = f;
		clr[i] = c;
		son[f].push_back(i);
	}
	dfs0(1);
	dfs1(1, false);
	printf("%d\n", ans);
	return 0;
}
