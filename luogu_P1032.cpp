#include<bits/stdc++.h>
using namespace std;
string a, b;
string f[30][3];
int lf, n;
bool dfs(string s, int i){
    if(i > n) return false;
    if(s == b){
        return true;
    }
    for (int j = 0; j < lf; ++j) {
        int p=-1;
        while((p = s.find(f[j][0], p+1)) != -1){
            string t = s;
            t.replace(p, f[j][0].size(), f[j][1]);
            if(dfs(t,  i+1)) return true;
        }
    }
    return false;
}
int main(){
    cin>>a>>b;
    while(cin>>f[lf][0]>>f[lf][1]) lf++;
    for(n = 1; n <= 10; n++){
        if(dfs(a, 0)){
			cout<<n<<endl;
			return 0;
		} 
    }
    cout<<"NO ANSWER!"<<endl;
    return 0;
}
