#include<iostream>
using namespace std;
int n, k, dp = 0;
int main(){
    cin >> n >> k;
    for(int i = 2; i <= n; ++i){
        dp = (dp + k) % i;
    }
    cout<<dp+1<<endl;  
    return 0;
}
