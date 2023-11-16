#include<bits/stdc++.h>
using namespace std;
int n, k, p;
vector<int> fa, r, po;
void init(){
    int i = 0, t = 0;
    while (t <= n){
        po.push_back(t);
        t = (int) pow(++i, p);
    }
}
void dfs(int i, int sum){
    if (i <= 0) return;
    if(fa.size() > k) return;
    if(fa.size() == k && sum == n){
        int a = accumulate(fa.begin(), fa.end(), 0), b = accumulate(r.begin(), r.end(), 0);
        if(a > b) r = fa;
        return;
    }
    int t = sum + (int)po[i];
    if(t <= n){
        fa.push_back(i);
        dfs(i, t);
        fa.pop_back();
    }
    dfs(i-1, sum);
}

int main(){
    scanf("%d%d%d", &n, &k, &p);
    init();
    dfs(po.size()-1 , 0);
    if(r.size()){
        printf("%d = ", n);
        for(int i = 0; i < r.size(); i++){
            if(i != 0) printf(" + ", n, k);
            printf("%d^%d", r[i], p);
        }
    }else printf("Impossible");
    return 0;
}
