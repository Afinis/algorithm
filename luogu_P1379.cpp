#include<bits/stdc++.h>
using namespace std;
string ed = "123804765", st;
int dir[] = {-3, 3, -1, 1}, en = 0, vis[9];
unordered_map<string, int> ma;
bool check(int p , int i){
    int np = p + dir[i];
    if(0 <= np && np < 9 && vis[np] == 0)
        if(i == 0 || i == 1 || (i == 2 && p % 3 != 0) || (i == 3 && p % 3 != 2) )
            return true;
    return false;
}
void dfs(int d, string g, int forward){
    if(d <= 0){
        if (forward) ma[g]++;
        else if(ma[g]) en = 1;
        return;
    }
    int p = g.find('0', 0);
    string t;
    for(int i = 0; i < 4; i++)
        if(check(p, i)){
            t = g;
            swap(t[p], t[p + dir[i]]);
            dfs(d-1, t, forward);
        }
}
int main(){
    cin>>st;
    int k = -1;
    while(en == 0){
        unordered_map<string, int> t;
        ma = t;
        k++;
        dfs(k/2, st, 1);
        dfs((k+1)/2, ed, 0);
    }
    cout<<k<<endl;
    return 0;
}
