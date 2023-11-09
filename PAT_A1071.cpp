#include<bits/stdc++.h>
using namespace std;

string s;
map<string, int > mm;
int main(){
    getline(cin, s);
    string t;
    for(int i = 0; i < s.size(); i++){
        if(('0' <= s[i] && s[i] <= '9')||('a'<=s[i] && s[i] <='z')
           ||('A'<=s[i]&&s[i]<='Z')){
            if('A'<=s[i]&&s[i]<='Z') t += s[i] - ('A'-'a');
            else t += s[i];
        }else{
            if(t.size()){
                mm[t]++;
                t = "";
            }
        }
    }
    if(t.size()){
        mm[t]++;
        t = "";
    }
    string r; int ma=0;
    for(auto it = mm.begin(); it!=mm.end(); it++){
        if(it->second > ma || (it->second == ma && r > it->first)){
            r = it->first;
            ma = it->second;
        }
    }
    cout<<r<<" "<<ma<<endl;
    return 0;
}
