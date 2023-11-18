#include<bits/stdc++.h>
using namespace std;
int n, m, T, ax, ay, bx, by, g[10][10], vis[10][10], c;
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
bool check(int x, int y){
    if(1 <= x && x <= n && 1 <= y && y <= m && vis[x][y] == 0 && g[x][y] == 0)
        return true;
    return false;
}
void dfs(int x, int y){
    if(x == bx && y == by){
        c++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + X[i], ny = y + Y[i];
        if(check(nx, ny)){
            vis[nx][ny] = 1;
            dfs(nx, ny );
            vis[nx][ny] = 0;
        }
    }
}
int main(){
    cin>>n>>m>>T>>ax>>ay>>bx>>by;
    for(int i = 0; i < T; i++){
        int x, y;
        cin>>x>>y;
        g[x][y] = 1;
    }
    vis[ax][ay]=1;
    dfs(ax, ay);
    cout<<c<<endl;
    return 0;
}
