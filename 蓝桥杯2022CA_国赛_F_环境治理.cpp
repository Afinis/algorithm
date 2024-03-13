#include<bits/stdc++.h>
using namespace std;
int n, Q, t[105][105], L[105][105], d[105][105];

void floyd(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
}

int sumD(){
	int c = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			c += d[i][j];
	return c;
}

void upd(int c, int k){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] = t[i][j];
			d[j][i] = t[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] -= c;
			d[j][i] -= c;
			if(i+1<=k){
				d[i][j]--;
				d[j][i]--;
			}
			if(d[i][j]<L[i][j]){
				d[i][j]=L[i][j];
			}
			if(d[j][i]<L[j][i]){
				d[j][i]=L[j][i];
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &Q);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &t[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &L[i][j]);
				
	int lo = 0, hi = n*(int)1e5;
	int p;
	while(lo < hi){
		int mi = (lo+hi)>>1;
		int c = mi/n, k = mi%n;
		upd(c, k);
		floyd();
		p=sumD();
		if(p>Q) lo = mi+1;
		else hi = mi;
	}
	int c = lo/n, k = lo%n;
	upd(c, k);
	floyd();
	p=sumD();
	if(p>Q) printf("-1\n");
	else printf("%d\n", lo);
	return 0;
}
