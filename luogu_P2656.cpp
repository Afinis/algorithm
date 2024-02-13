#include<bits/stdc++.h>
using namespace std;
const int N = 8*10000+5, M = 2*100000+5, INF = 0x7fffffff;
struct node{
    int to, last, e;
    int k;
};
int le, he[N], lc, hc[N], ind[N], csum[N], dp[N];
node e[M*2], ec[M*2];
int n, m, s;
int dfn[N], low[N], c, ins[N], cid[N], num;
stack<int> sta;
void tarjan(int i){
    dfn[i] = low[i] = ++c;
    sta.push(i); ins[i] = 1;
    for(int j = he[i]; j ; j = e[j].last){
        int v = e[j].to;
        if(!dfn[v]){
            tarjan(v);
            low[i] = min(low[i], low[v]);
        }else if(ins[v]){
            low[i] = min(low[i], dfn[v] );
        }
    }
    if(dfn[i] == low[i]){
        num++;
        int v;
        do{
            v = sta.top(); sta.pop(); ins[v] = 0;
            cid[v] = num;
        }while(i != v);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y, t;
        double k;
        scanf("%d%d%d%lf", &x, &y, &t, &k);
        le++;
        e[le].to = y;
        e[le].last = he[x];
        e[le].e = t;
        e[le].k = k*10;
        he[x] = le;
    }
    scanf("%d", &s);
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int u=1;u<=n;u++){
        for(int i = he[u]; i ; i = e[i].last){
            int v = e[i].to;
            if(cid[u] != cid[v]){
                lc++;
                ec[lc].to = cid[v];
                ec[lc].last = hc[cid[u]];
                ec[lc].e = e[i].e;
                hc[cid[u]] = lc;
                ind[cid[v]]++;
            }else{
                int g = 0, t = e[i].e;
                while(t){
                    g += t;
                    t *= e[i].k;
                    t /= 10;
                }
                csum[cid[u]] += g;
            }
        }
    }
    //拓扑排序
    //dp[i]定义为起点s到i采到的最大的蘑菇数
    queue<int> q; //用队列来储存入度为0的点
    for(int i=1;i<=num;i++){
        if(!ind[i]) q.push(i);
        dp[i] = -INF;
    }
    dp[cid[s]] = csum[cid[s]];
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=hc[u]; i; i=ec[i].last){
            int v = ec[i].to;
            dp[v] = max(dp[v], dp[u] + ec[i].e + csum[v]);
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
    int ans = 0;
    for(int i=1;i<=num;i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}
