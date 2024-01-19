#include<bits/stdc++.h>
using namespace std;
const int M = 100000 + 5;
int a[M];
vector<int> v, l;

int main(){
    int c = 0;
    while(scanf("%d", &a[c]) != EOF) c++;

    for(int i = 0; i < c; i++){
        int lo = 0, hi = v.size();
        while(lo < hi){
            int mi = (lo+hi)>>1;
            if(v[mi] >= a[i]){
                lo = mi + 1;
            }else{
                hi = mi;
            }
        }
        if(lo == v.size()){
            v.push_back(a[i]);
        }else{
            v[lo] = a[i];
        }

//        int q = upper_bound(v.begin(), v.end(), a[i], greater<int>() ) - v.begin();
//        if (q == v.size()){
//            v.push_back(a[i]);
//        } else v[q] = a[i];

        int p = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
        if(p == l.size()){
            l.push_back(a[i]);
        }else
            l[p] = a[i];
    }

    printf("%d\n%d\n", v.size(), l.size());
//    getchar();
    return 0;
}
