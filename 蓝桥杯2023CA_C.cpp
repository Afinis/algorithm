#include<bits/stdc++.h>
using namespace std;
//��ȡ[1, x]��4�ı����������ĸ�����ǰ����ȡ����������ȡ��
long long get_sum(long long x){
    return x / 4 + (x + 1) / 2;
}
int main(){
    long long l, r;
    cin>>l>>r;
    cout<<get_sum(r) - get_sum(l - 1)<<endl;
    return 0;
}
