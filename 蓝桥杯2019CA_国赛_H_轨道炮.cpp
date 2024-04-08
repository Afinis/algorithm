#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e6;
int n, x[N], y[N], vx[N], vy[N], h[M], cnt, ans;

void check(int i, int * a, int * v){
	int r = 0;
	cnt = 0; 
	memset(h, 0, sizeof h);
	for(int j = 0; j < n; j++){
		if(i==j) continue;
		if(a[i]==a[j]&&v[i]==v[j]){
			cnt++;
		}else if(v[i]!=v[j]){
			int dx = a[i]-a[j];
			int dv = v[j]-v[i];
			int t = dx/dv;
			if(dx%dv==0&&t>=0){
				h[t]++;
				r = max(r, h[t]);
			}
		}
	}
	r += cnt;
	ans = max(r, ans);
}


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int v;
		char d[3];
		scanf("%d%d%d%s", &x[i], &y[i], &v, d);
		if(d[0]=='U'){
			vx[0]=0, vy[i]=v;
		}else if(d[0]=='D'){
			vx[i]=0, vy[i]=-v;
		}else if(d[0]=='L'){
			vx[i]=-v, vy[i]=0;
		}else if(d[0]=='R'){
			vx[i]=v, vy[i]=0;
		}
	}
	for(int i = 0; i < n; i++){
		check(i, x, vx);
		check(i, y, vy);
	}
	printf("%d\n", ans+1);
	return 0;
}
