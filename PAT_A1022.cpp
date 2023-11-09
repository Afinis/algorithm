#include<bits/stdc++.h>
using namespace std;
map<string, vector<string> >title, author, key, publisher;
map<int, vector<string> > year;
void myprint(vector<string> v){
	sort(v.begin(), v.end());
    for(int j = 0; j < v.size(); j++) cout<<v[j]<<endl;
	if(v.size()==0) cout<<"Not Found"<<endl;
}
int main(){
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        string id, t;
        getline(cin, id);
        getline(cin, id);
        getline(cin, t); title[t].push_back(id);
        getline(cin, t); author[t].push_back(id);
        getline(cin, t);
        for(int i = t.find(' '), be = 0; 1; ){
            string sub = t.substr(be, i-be);
            key[sub].push_back(id);
            be = i+1;
            if (be >= t.size()) break;
            i = find(t.begin() + be, t.end(), ' ') - t.begin();
        }
        getline(cin, t); publisher[t].push_back(id);
        int y; cin>>y; year[y].push_back(id);
    }
    int m; cin>>m; string t; getline(cin, t);
    for(int i = 0; i < m; i++){
        string s; getline(cin, s);
        cout<<s<<endl;
        string t = s.substr(3, s.size()-2);
        switch(s[0]){
            case '1':{
                myprint(title[t]);
				break;
            }case '2':{
                myprint(author[t]);
				break;
            }case '3':{
            	myprint(key[t]);
				break;
			}case '4':{
            	myprint(publisher[t]);
				break;
			}case '5':{
            	myprint(year[atoi(t.c_str())]);
				break;
			}
        }
    }
    return 0;
}
