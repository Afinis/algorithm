#include<bits/stdc++.h>
using namespace std;
//获取[1, x]中4的倍数和奇数的个数，前者下取整，后者上取整
long long get_sum(long long x){
    return x / 4 + (x + 1) / 2;
}
int main(){
    long long l, r;
    cin>>l>>r;
    cout<<get_sum(r) - get_sum(l - 1)<<endl;
    return 0;
}
