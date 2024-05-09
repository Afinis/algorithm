#include<bits/stdc++.h>
using namespace std;
#define int long long

//欧拉函数 
int get_eular(int n){
    int phi=n;
    for(int i=2;i<=n/i;i++){
        if(n%i) continue;
        while(n%i==0) n/=i;
        phi=phi/i*(i-1);
    }
    if(n>1) phi=phi/n*(n-1);
    return phi;
} 

//快速幂
int quick(int base, int x, int mod){
    int res=1;
    while(x){
        if(x&1) res=res*base%mod;
        base=base*base%mod;
        x>>=1;
    }
    return res;
} 

signed main(){
    int a=get_eular(2023); 
    int t=2023; 
    for(int i=2022;i>=3;i--){
        t=quick(i,t,a);
    }
    t=quick(2,t,2023);
    cout<<t<<endl;    
    return 0;
}

