#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5, M = 1000000007;
int p[N], t[N], r;
int main(){
    string s; cin>>s;
    for(int i = 0; i < s.size(); i++)
        if(s[i]=='P') i == 0 ? p[i] = 1 : p[i] = p[i-1] + 1;
    for(int i = s.size()-1; i >= 0; i--)
        if(s[i]=='T') i == s.size()-1 ? t[i] = 1 : t[i] = t[i+1] + 1;
    for(int i = 0; i < s.size(); i++)
        if(s[i]=='A') r = (r + p[i]*t[i])%M;
    cout<<r<<endl;
    return 0;
}
