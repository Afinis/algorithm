#include<bits/stdc++.h>
using namespace std;
int n, vis[20];
double r = 1e11, x[20], y[20], dis[1<<17][20];
void dfs(double a, double b, int c, double d, int path){
	if(d > r) return;
 	if(c == n){
		r = min(r, d);
		return;
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			double t = d + sqrt((a-x[i])*(a-x[i]) + (b-y[i])*(b-y[i]));
			int newp = path+(1<<i);
			if(dis[newp][i] == 0 || dis[path+(1<<i)][i] > t){
				dis[newp][i] = t;
				vis[i] = 1;
				dfs(x[i], y[i], c+1, t, newp );
				vis[i] = 0;
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i = 0;i < n; i++) cin>>x[i]>>y[i];
	dfs(0, 0, 0, 0, 0);
	cout<<fixed<<setprecision(2)<<r<<endl;
	return 0;
}
