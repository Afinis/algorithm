#include<bits/stdc++.h>
using namespace std;
struct node{
	int h,m,s;
	int status;
};
map<string, vector<node> > mm;
map<string, vector<node> > vv;
map<int, vector<string> > r;
bool mycmp(node a, node b){
	if(a.h != b.h) return a.h < b.h;
	else if(a.m != b.m) return a.m < b.m;
	else if(a.s != b.s) return a.s < b.s;
	return true;
}

int last(node a, node b){
    return (b.h-a.h)*60*60 + (b.m-a.m)*60 + (b.s-a.s);
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		char t[5];
		char na[10];
		node no;
		int sta;
		scanf("%s %d:%d:%d %s", na, &no.h, &no.m, &no.s, t);
		if(strcmp(t, "in")) no.status = 1;
		else no.status = 0;
		mm[string(na)].push_back(no);
	}
	int dis = 0;
	for(auto it = mm.begin(); it != mm.end(); it++){
		auto e = it->second;
		string na = it->first;
		sort(e.begin(), e.end(), mycmp);
		int d = 0;
		for(int i = 0; i < e.size(); i++){
			if(i != e.size()-1 && e[i].status == 0 && e[i+1].status == 1){
				vv[na].push_back(e[i]);
				vv[na].push_back(e[i+1]);
				d += last(e[i], e[i+1]);
			}
		}
		if(dis < d){
			r[d].push_back(na);
			dis = d;
		}else if(dis == d){
			r[d].push_back(na);
		}
	}	
	vector<node> q;
	for(auto it = vv.begin(); it != vv.end(); it++){
		q.insert(q.end(), it->second.begin(), it->second.end() );
	}
	sort(q.begin(), q.end(), mycmp);	
	
	for(int i = 0; i < k; i++){
		node t;
		scanf("%d:%d:%d", &t.h, &t.m, &t.s);
		int c = 0;
		for(int j = 0; j < q.size() && mycmp(q[j], t); j++){
			if(q[j].status == 0){
				c++;
			}else if( q[j].status == 1 ){
				c--;
			}
		}
		printf("%d\n", c);
	}
	auto t = r[dis];
	sort(t.begin(), t.end()); 
	for(int i = 0; i < t.size(); i++){
		printf("%s ", t[i].c_str());
	}
	int h = dis/60/60;
	int m = dis/60 - h*60;
	int s = dis - m*60 - h*60*60;
	printf("%02d:%02d:%02d", h, m, s );
}
