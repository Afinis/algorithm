#include<bits/stdc++.h>
using namespace std;

int n, tl, ip;
vector< pair<string, vector <pair<string, int> > > > v;
map< string,  map<string, int>  > mm;
map<string, int> sum;

bool mycmp(pair<string, vector <pair<string, int> > > a, pair<string, vector <pair<string, int> > > b){
    if(a.second.size() > b.second.size() ){
        return true;
    }else if( a.second.size() < b.second.size() ){
        return false;
    }else{
        return a.first < b.first;
    }
}

bool mycmp2(pair<string, int> a, pair<string, int> b){
    if(a.second > b.second){
        return true;
    }else if( a.second < b.second ){
        return false;
    }else{
        return a < b;
    }
}

int main(){
    cin>>n>>ip>>tl;
    for(int i = 0; i < n; i++){
        string t, t1;
        cin>>t>>t1;
        mm[t][t1]++;
        sum[t]++;
    }

    for(auto it = mm.begin(); it!= mm.end(); it++){
        pair<string, vector <pair<string, int> > >  t;
        t.first = it->first;
        vector <pair<string, int> > vt(it->second.begin(), it->second.end());
        sort(vt.begin(), vt.end(), mycmp2);
        t.second = vt;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), mycmp);

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second.size() > ip && sum[v[i].first ] > tl){
            cnt++;
            cout<< v[i].first <<endl;
            vector <pair<string, int> > t = v[i].second;
            for(int j = 0; j < t.size(); j++){
                cout<< t[j].first <<" "<< t[j].second <<endl;
            }
        }

    }
    if(cnt==0){
    	int si = v[0].second.size();
    	for(int i = 0; i < v.size(); i++){
    		if(v[i].second.size() == si){
    			cout<< v[i].first <<endl;
		        vector <pair<string, int> > t = v[i].second;
		        for(int j = 0; j < t.size(); j++){
		            cout<< t[j].first <<" "<< t[j].second <<endl;
		        }
			}else{
				break;
			}	
		}     
    }

    return 0;
}
