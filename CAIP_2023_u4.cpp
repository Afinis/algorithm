#include<bits/stdc++.h>
using namespace std;
const int N = 4000 + 5;
int n;
map<string, int> id;
vector<int> g[N];
map<int, string> name;

int vis[N], pre[N];

vector<int> bfs(int st, int en){
	memset(pre,0, sizeof(pre));
	memset(vis,0, sizeof(vis));
	vector<int> r;
	queue<int> q;
	q.push(st);
	vis[st]=1;
	
	while(!q.empty()){
		int v = q.front(); q.pop();
		if(v == en){
			int p = en;
			while(p){
				r.push_back(p);
				p = pre[p];
			}
			break;
		}	
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if(!vis[u]){
				q.push(u); vis[u]=1;
				pre[u] = v;
			}
		}
	}
	return r;
}


int main(){
	int m;
	cin>>m;
	for(int i = 0; i < m; i++){
		string s1, s2;
		int t1, t2;
		cin>>s1>>t1>>s2>>t2;
		if(id.count(s1) == 0){
			n += 2;
			id[s1] = n-1;
			name[n-1] = name[n] = s1;
		}
		if(id.count(s2) == 0){
			n += 2;
			id[s2] = n-1;
			name[n-1] = name[n] = s2;
		}
		g[id[s1] + t1].push_back( id[s2] + t2);
	}
	vector<int> r(N);
	for(int i = 2; i <= n; i+= 2){
		vector<int> t = bfs(i-1, i);
		if(t.size() && t.size() < r.size()){
			r = t;
		}
		t = bfs(i, i-1);
		if(t.size() && t.size() < r.size()){
			r = t;
		}
	}
	
	for(int i = r.size()-1; i >= 0; i--){
		if(i == 0 || i == r.size()-1){
			cout<<name[r[i]]<<" "<<(r[i]+1)%2<<" ";
		}else{
			cout<<name[r[i]]<<" "<<(r[i]+1)%2<<" "<<name[r[i]]<<" "<<(r[i]+1)%2<<" ";
		}
	}
	cout<<"= "<<name[r[r.size()-1]]<<" "<<(r[r.size()-1]+1)%2<<" "<<name[r[0]]<<" "<<(r[0]+1)%2;
	return 0;
}
