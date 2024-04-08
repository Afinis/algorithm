#include<bits/stdc++.h>
using namespace std; 
#define ls p*2
#define rs p*2+1
const int N = 2e5+10;
int n, Y[N];

struct line{
    int y1, y2, x;
    int flag;
}L[N];

bool cmp(line a, line b){
    return a.x < b.x;
}

struct tre{
    int l, r;
    int cnt, l1, l2;
}t[N*8];

void build(int l, int r, int p){
    t[p] = {l, r, 0, 0, 0};
    if(l==r){
        return;
    }
    int mi = l+r>>1; 
    build(l, mi, ls);
    build(mi+1, r, rs);
}

void pushUp(int p){
    if(t[p].cnt != 0){
        if(t[p].cnt%2==1){
            t[p].l2 = t[ls].l1 + t[rs].l1;
            t[p].l1 = Y[t[p].r+1]-Y[t[p].l] - t[p].l2;
        }else{
            t[p].l1 = t[ls].l1 + t[rs].l1;
            t[p].l2 = Y[t[p].r+1]-Y[t[p].l] - t[p].l1;
        }
    }else{
        t[p].l1 = t[ls].l1 + t[rs].l1;
        t[p].l2 = t[ls].l2 + t[rs].l2;
    }
}

void update(int l, int r, int p, int flag){
    if(l <= t[p].l && t[p].r <= r){
        t[p].cnt += flag;
        pushUp(p);
        return;
    }
    int mi = t[p].l + t[p].r>>1;
    if(l <= mi) update(l, r, ls, flag);
    if(mi < r) update(l, r, rs, flag);
    pushUp(p);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        L[i] = {y1, y2, x1, 1};
        L[i+n] = {y1, y2, x2, -1};
        Y[i] = y1;
        Y[i+n] = y2;
    }
    n *= 2;
    sort(Y, Y+n);
    int ly = unique(Y, Y+n) - Y;
    sort(L, L+n, cmp);
    build(0, ly-1-1, 1);
    long long od = 0, ev = 0;
    for(int i = 0; i < n-1; i++){
        int l = lower_bound(Y, Y+ly, L[i].y1) - Y;
        int r = lower_bound(Y, Y+ly, L[i].y2) - Y;
        update(l, r-1, 1, L[i].flag);
        od += 1ll*t[1].l1 * (L[i+1].x-L[i].x);
        ev += 1ll*t[1].l2 * (L[i+1].x-L[i].x);
    }
    printf("%lld\n%lld\n", od, ev);
    return 0;
}
