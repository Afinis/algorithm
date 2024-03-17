#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2*10e5+10, INF = 1e6;
ll n, m;
ll a[N], b[N], pre[N], cnt_pre[N], L[N], R[N];

struct hjtree{
    ll ls, rs, sum, sqs, cnt;
}t[N<<5];
ll root[N], cnt;

void pushUp(ll o){
    t[o].sum = t[t[o].ls].sum + t[t[o].rs].sum;
    t[o].sqs = t[t[o].ls].sqs + t[t[o].rs].sqs;
    t[o].cnt = t[t[o].ls].cnt + t[t[o].rs].cnt;
}

void build(ll &o, ll pre, ll l, ll r, ll x, ll v){
    o = ++cnt;
    if (o==22){
        ll ppp = 0;
    }
    t[o] = t[pre];
    if(l == r){
        t[o].sum += v;
        t[o].sqs += v*v;
        t[o].cnt++;
        return;
    }
    ll mi = (l+r)>>1;
    if(x <= mi) build(t[o].ls, t[pre].ls, l, mi, x, v);
    else build(t[o].rs, t[pre].rs, mi+1, r, x, v);
    pushUp(o);
}

ll query(ll ox, ll oy, ll l, ll r, ll ql, ll qr, ll typ){
    if(ql<=l && r<=qr){
        if(typ == 1){
            return t[ox].sum - t[oy].sum;
        }else if(typ == 2){
            return t[ox].sqs - t[oy].sqs;
        }else{
            return t[ox].cnt - t[oy].cnt;
        }
    }
    ll sum = 0, mi = (l+r)/2;
    if(ql <= mi){
        sum += query(t[ox].ls, t[oy].ls, l, mi, ql, qr, typ);
    }
    if(mi < qr){
        sum += query(t[ox].rs, t[oy].rs, mi+1, r, ql, qr, typ);
    }
    return sum;
}

ll calc(ll i, ll l, ll r, ll h){
    ll v1, v2;
    if (b[i] == 0) v1 = l, v2 = r;
    if (b[i] == 1) v1 = a[i] - r + 1, v2 = a[i] - l + 1;

    if (h <= v1) return h * (r - l + 1);
    if (h > v2)  return (v2 + v1) * (r - l + 1) / 2;
    return (v2 - h) * h + (h + v1) * (h - v1 + 1) / 2;
}


int main(){
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++){
        scanf("%lld%lld", &a[i], &b[i]);
        build(root[i], root[i-1], 1, INF, a[i], a[i]);
        pre[i] = pre[i-1] + a[i];
        cnt_pre[i] = cnt_pre[i-1] + a[i]*(a[i]+1)/2;
        L[i] = pre[i-1]+1, R[i] = pre[i];
    }
    for(ll i = 1; i <= m; i++){
        ll l, r, v;
        scanf("%lld%lld%lld", &l, &r, &v);
        ll li = lower_bound(pre+1, pre+1+n, l) - pre;
        ll ri = lower_bound(pre+1, pre+1+n, r) - pre;
        ll lo = 1, hi = INF+1, ans = -1;
        while(lo < hi){
            ll mi = (lo+hi)/2;
            ll res = 0;
            if(li == ri){
                res = calc(li, l-L[li]+1, r-L[li]+1, mi);
            }else{
                ll tsum = query(root[ri-1],root[li],1,INF,mi,INF,1)-query(root[ri-1],root[li],1,INF,mi,mi,1);
                ll tsqs = query(root[ri-1],root[li],1,INF,mi,INF,2)-query(root[ri-1],root[li],1,INF,mi,mi,2);
                ll tcnt = query(root[ri-1],root[li],1,INF,mi,INF,3)-query(root[ri-1],root[li],1,INF,mi,mi,3);
                res = (tsqs - 2*tsum*mi+tcnt*mi*mi + tsum-tcnt*mi)/2;
                res = cnt_pre[ri - 1] - cnt_pre[li] - res;
                res += calc(li, l - L[li] + 1, R[li] - L[li] + 1, mi) + calc(ri, 1, r - L[ri] + 1, mi);
            }
            if(res >= v){
                ans = mi;
                hi = mi;
            }else{
                lo = mi+1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
