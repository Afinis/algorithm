#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;;
const int N=1010;

int n,m,k;
int w[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
PII t[N];
//只考虑前i个物品能否组成体积为j的情况
bool f[N][5*N];
int main()
{
    for(int i=1;i<=12;++i) w[i]+=w[i-1];
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        t[i]={w[a-1]+b,c};
    }
    //按日期排序
    sort(t+1,t+n+1);
    f[0][0]=true;
    //双指针
    int l=0;
    for(int i=1;i<=n;++i){
        //找到上一个可选的票据
        while(t[i].first-t[l+1].first>=k) l++;
        for(int j=0;j<=m;++j){
            f[i][j]=f[i-1][j];
            if(j>=t[i].second) f[i][j]|=f[l][j-t[i].second];
        }
    }
    for(int v=m;v>=0;--v){
        if(f[n][v]){
            printf("%d\n",v);
            return 0;
        }
    }
}
