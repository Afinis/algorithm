 #include<bits/stdc++.h>
 using namespace std;
 
int n, ma = 1000000;
map<pair<string, int>, vector<pair<string, int> > > mm;

vector<pair<string, int> > v, q, r;

void dfs( pair<string, int> p, pair<string, int> ne , int o){
	int l = mm[ne].size();
	
	if( o && ne.first == p.first && ne.second != p.second){
		if(ma > o){
			ma=o;
			r =v;
		}
		
		return;
	}
	bool fl = false;
	for(int i = 0; i <l; i++){
		v.push_back(mm[ne][i]);
		dfs(p, mm[ne][i], o+1);
		v.pop_back();
	}
}

 int main(){
 	cin>>n;
	for(int i = 0 ;i < n; i++){
		string t1, t2;
		int a1, a2;
		cin>>t1>>a1>>t2>>a2;
		mm[{t1, a1}].push_back({t2, a2});
		q.push_back({t1, a1});
	}
	for(int k = 0; k < n; k++){
		int l = mm[q[k]].size();
		for(int i = 0; i < l; i++){
			v.push_back(q[k]);
			dfs(q[k], mm[q[k]][i], 0);
			v.pop_back();	
		}
	}
	for(int j = 0; j < r.size(); j++){
					cout<<r[j].first<<" "<<r[j].second<<" ";
				}
				cout<<"= "<<r[0].first<<" "<<r[0].second<<" "<<r[r.size()-1].first<<" "<<r[r.size()-1].second;
			
 	return 0;
 }
