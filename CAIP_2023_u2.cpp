#include<bits/stdc++.h>
using namespace std;

map<string, string> mm;

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        string t,y;
        cin>>t>>y;
        mm[t]=y;
    }

    for(int i = 0; i < m; i++){
        string t, r;
        cin>>t;
        int c= 0;
        if(mm[t] != ""){
        	cout<<mm[t]<<endl;
		}else{
			for(int j = 1; j <= t.size(); j++){
	        	string a = string(t, 0, j);
	        	string b = string(t, j, t.size()-j);
	        	if(mm[a] != "" && mm[b] != ""){
	        		c++;
	        		r = mm[a]+mm[b];
				}	
			}
			if(c==1) cout<<r<<endl;
			else cout<<"D"<<endl;
		}
        
    }
    return 0;
}
