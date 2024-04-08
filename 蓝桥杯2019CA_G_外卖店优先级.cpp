#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
priority_queue<int, vector<int>, greater<int> > q[N];
int n, m, t, c[N], ans;

int main(){
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 0; i < m; i++){
		int ts, id;
		scanf("%d%d", &ts, &id);
		q[id].push(ts);
	}
	for(int i = 1; i <= n; i++){
		int pre = 0, ts = 0;
		bool pi = false;
		while(!q[i].empty()){
			ts = q[i].top(); q[i].pop();
			if(ts!=pre) c[i] -= (ts-pre-1);
			if(c[i]<0) c[i]=0;
			if(pi && c[i]<=3) pi = false;
			c[i] += 2;
			if(c[i] > 5) pi = true;
			pre = ts;
		}
		if(t!=ts){
			c[i] -= (t-ts);
			if(c[i]<0) c[i]=0;
			if(pi && c[i]<=3) pi = false;
		}
		if(pi) ans++;
	}
	printf("%d", ans);
	return 0;
}
