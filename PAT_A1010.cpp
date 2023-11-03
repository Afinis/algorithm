// ¶þ·ÖÐÞ¸Ä
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tag,radix;
string a,b;
ll decimalNum(string a, ll r){
    ll t = 0, e = 0, c = 0;
    for(ll i = 0; i < a.size() ; i++){
        '0' <= a[i] && a[i] <= '9' ? e = a[i] - '0' : e = a[i] - 'a' + 10;
        t = t*r + e;
        if(t < 0) return -1;
    }
    return t;
}
ll radixMin(string a){
    ll m = 2, e = 0;
    for(ll i = 0; i < a.size() ; i++){
        '0' <= a[i] && a[i] <= '9' ? e = a[i] - '0' : e = a[i] - 'a' + 10;
        m = max(m, e+1);
    }
    return m;
}
int main(){
    cin>>a>>b>>tag>>radix;
    if(tag == 2) swap(a,b);
    ll c = decimalNum(a, radix);
    ll lo = max(radixMin(b), 2LL);
    ll hi = max(lo, c)+1;
    ll t = 0, mi = 0;
    while(lo <= hi){
        mi = (lo+hi)/2;
        t = decimalNum(b, mi);
        if (t == c) break;
        else if(t > 0 && t < c) lo = mi + 1;
        else hi = mi-1;
    }
    t == c ? cout<<mi : cout<<"Impossible";
    return 0;
}
