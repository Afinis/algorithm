#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int p[6], acc[N+5], fool[N+5], per[N+5];

vector<int> v[N+5];

bool mycmp(vector<int> a, vector<int> b){
	if(acc[a[0]] > acc[b[0]]) return true;
	else if(acc[a[0]] < acc[b[0]]) return false;
	
	if(per[a[0]] > per[b[0] ]) return true;
	else if(per[a[0]] < per[b[0] ]) return false;
	
	return a[0]<b[0];
}


int main(){
	int n,k,m;
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <=k; i++) scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++){
		v[i].push_back(i);
		v[i].resize(6, -2);		
	}
	
	for(int i = 1; i<=m; i++){
		int id, pid, s;
		scanf("%d%d%d", &id, &pid, &s );
		if(v[id][pid] < s) v[id][pid] = s;
	}
	
	for(int i = 1; i <= n; i++){
		int sum = 0, flag = 1, c=0;
		for(int j = 1; j <= k; j++){
			if(v[i][j] >= 0){
				sum += v[i][j];
				flag=0;
				if(v[i][j] == p[j]) c++;
			}
		}
		if(flag){
			fool[i]=flag;
			sum = -1;
		}
		per[i]=c;
		acc[i] = sum;
	}
	
	sort(v+1, v+1+n, mycmp);
	int rank = 1;
	for(int i = 1; i <=n; i++){
		if(acc[v[i][0]] == -1) break;
		printf("%d ", rank);
		if(i+1 > n || acc[v[i+1][0]] != acc[v[i][0]]) rank=i+1;
		printf("%05d ", v[i][0]);
		printf("%d ", acc[v[i][0]]);
		for(int j = 1; j <=k; j++){
			if(v[i][j] == -2) printf("-");
			else if(v[i][j] == -1) printf("0");
			else printf("%d", v[i][j]);
			if(j != k) printf(" ");		
		}
		printf("\n");
	}
	return 0;
}
