#include<bits/stdc++.h>
using namespace std;

vector<pair<string, int>> v[4], rr[4];
int n,m;
bool mysort(pair<string, int> a, pair<string, int> b){
	return a.second > b.second;
}
string ff;
bool myfind(pair<string, int> e){
	return e.first == ff;
}
string cou[4] = {"A", "C", "M", "E"};

int main(){
    cin>>n>>m;
	for(int i = 0; i < n; i++){
		string id; cin>>id;
		int t1, t2, t3, t4;
		cin>>t1; v[1].push_back({id, t1});
        cin>>t2; v[2].push_back({id, t2});
        cin>>t3; v[3].push_back({id, t3});
		t4=(t1 + t2 + t3)/3; v[0].push_back({id, t4});
	}
    for(auto & i : v) sort(i.begin(), i.end(), mysort);
    for (int j = 0; j < 4; ++j) {
        int pre = 0, pr = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0){
                rr[j].push_back({v[j][i].first, 1});
                pre = v[j][i].second;
                pr = 1;
            } else
                if (pre == v[j][i].second) rr[j].push_back({v[j][i].first, pr});
                else{
                    rr[j].push_back({v[j][i].first, i+1});
                    pr = i+1;
                    pre = v[j][i].second;
                }
        }
    }
	for(int i = 0; i < m; i++){
		cin>>ff;
        int r = 50000, c;
        for (int j = 0; j < 4; ++j) {
            auto it = find_if(rr[j].begin(), rr[j].end(), myfind);
            if (it == rr[j].end()){
                r = -1; break;
            }
            if (r > it->second){
                r = it->second; c = j;
            }
        }
        if (r == -1) cout<<"N/A"<<endl;
        else cout<<r<<" "<<cou[c]<<endl;
	}
	return 0;
}
