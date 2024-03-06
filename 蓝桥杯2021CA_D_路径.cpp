#include<bits/stdc++.h>
using namespace std;
const int n = 2021, MAX=1e8;

int gcd(int a, int b){
	return a==0? b : gcd(b%a, a);
}

int gca(int a, int b){
	return a*b/gcd(a, b);
}

struct node{
	int to, last, w;
}e[3000000];
int head[3000000], ch;

void add(int u, int v, int w){
	e[++ch].to = v;
	e[ch].w = w;
	e[ch].last = head[u];
	head[u] = ch;
}

int vis[2025], d[2025];
vector<int> v;

void dij(int i){
	fill(d, d+2025, MAX);
	d[i]=0;
	while(true){
		int mi=MAX, u=-1;
		for(int j = 1; j <= n; j++)
			if(vis[j]==0 && d[j] < mi){
				mi = d[j];
				u = j;
			}
		if(u==-1) break;
		vis[u]=1;
		for(int j = head[u]; j; j = e[j].last){
			int to = e[j].to;
			if(vis[to]==0 && d[to]>d[u]+e[j].w)
				d[to]=d[u]+e[j].w;
		}
	}
}

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= i+21 && j <= n; j++){	
			int t = gca(i, j);
			add(i, j, t);
			add(j, i, t);
		}
	}
	dij(1);
	cout<<d[2021]<<endl;
	return 0;
}
