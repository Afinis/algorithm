#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int s=0;s<=6;++s){
        for(int f=0;f<60;++f){
            for(int m=0;m<60;++m){
                if(s==0&&f==0&&m==0) continue;
                double dm=360*m/60;
                double df=360*f/60+dm/60;
                double ds=360*s/12+df/12;
                double A=abs(df-ds),B=abs(df-dm);
                //取小的角度
                A=min(A,360-A);
                B=min(B,360-B);
                if(fabs(A-2*B)<=1e-10){
                    printf("%d %d %d\n",s,f,m);
                }
            }
        }
    }
    return 0;
}
