#include<bits/stdc++.h>
using namespace std;
int n;
bool myfind(char a){
    if('0' < a &&  a <= '9') return true;
    else return false;
}
string conver(string s){
    int t = s.find(".");
    // 小数点的位置
    int l = t==string::npos ? s.size(): t;
    // 第一个非零元素的位置
    int p = find_if(s.begin(), s.end(), myfind) - s.begin();
//    p = p == s.size() ? l + 1 : p;
    if (p == s.size()){
        string r = "0.";
        int c = n;
        while (c--){
            r += "0";
        }
        return r += "*10^0";
    }
    string t2 = s;
    string front = t2.erase(l, 1).substr(p < l ? p : p-1, n);
    string r = "0.";
    r+=front;
    if(p+n > s.size()){
        int c = p+n-s.size();
        while(c--) r+="0";
    }
    int k = l-p < 0 ? l-p+1 : l-p;
    r+="*10^" + to_string(k);
    return r;
}
int main(){
    string a, b;
    cin>>n>>a>>b;
    a = conver(a);
    b = conver(b);
    a == b ? cout<<"YES "<<a<<endl : cout<<"NO "<<a<<" "<<b<<endl;
    return 0;
}
