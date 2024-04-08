#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10, M = 20;
struct node{
    ll to, last;
    ll v;
}e[2*N];
ll head[N], ec;
ll lane[N], sum;
ll n, k, a[N], dep[N], fa[N][M+10], dis[N];
void add(ll u, ll v, ll t){
    ec++;
    e[ec].to = v;
    e[ec].v = t;
    e[ec].last = head[u];
    head[u] = ec;
}

void dfs(ll i, ll p, ll v){
    dep[i] = dep[p]+1;
    dis[i] = dis[p]+v;
    fa[i][0] = p;
    for(ll j = 1; j <= M; j++){
        fa[i][j] = fa[fa[i][j-1]][j-1];
    }

    for(ll j = head[i]; j; j = e[j].last){
        if(e[j].to == p) continue;
        dfs(e[j].to, i, e[j].v);
    }
}

ll lca(ll x, ll y){
    if(dep[x] < dep[y]) swap(x, y);
    ll d = dep[x] - dep[y];
    for(ll i = 0; d; i++, d>>=1){
        if(d&1) x = fa[x][i];
    }
    if(x==y) return x;
    for(ll i = M; i >= 0 && x != y; i--){
        if(fa[x][i] != fa[y][i] ){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

ll getDis(ll x, ll y){
    if(x==0 || y == 0) return 0;
    return dis[x] + dis[y] - 2*dis[lca(x, y)];
}

int main(){
    scanf("%lld%lld", &n, &k);
    for(ll i = 1; i < n; i++){
        ll u, v, t;
        scanf("%lld%lld%lld", &u, &v, &t);
        add(u, v, t);
        add(v, u, t);
    }
    for(ll i = 1; i <= k; i++){
        scanf("%lld", &a[i]);
    }
    dfs(1, 0, 0);
    for(ll i = 1; i < k; i++){
        lane[i+1] = getDis(a[i], a[i+1]);
        sum += lane[i+1];
    }
    for(ll i = 1; i <= k; i++){
        ll d1 = getDis(a[i], a[i-1]);
        ll d2 = getDis(a[i], a[i+1]);
        ll d3 = getDis(a[i-1], a[i+1]);
        printf("%lld ", sum-d1-d2+d3);
    }
    return 0;
}
