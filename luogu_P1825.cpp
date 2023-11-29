#include<bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int n, m, begx, begy, r, inq[305][305];
char g[305][305];
map<char, pair<int, int> > sm;
map<pair<int, int>, pair<int, int> > ma;
struct node{
    int x, y, t;
};
bool check(int x, int y){
    if(0<=x && x<n && 0<=y && y<m &&g[x][y]!='#' && inq[x][y]==0)
        return true;
    return false;
}

void bfs(int x, int y){
    queue<node > q;
    node e; e.x=x; e.y=y; e.t=0;
    q.push(e);
    inq[x][y]= 1;
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(g[t.x][t.y] == '='){
            r = t.t;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = t.x + X[i];
            int ny = t.y + Y[i];
            if(check(nx, ny)){
                node x;
                if('A' <= g[nx][ny] && g[nx][ny] <= 'Z'){
                    int tx = ma[{nx, ny}].first, ty = ma[{nx, ny}].second;
                    x.x = tx;
                    x.y = ty;
                }else{
                    x.x = nx;
                    x.y = ny;
                    inq[nx][ny] = 1;
                }
                x.t = t.t+1;
                q.push(x);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
            if(g[i][j] == '@'){
                begx = i;
                begy = j;
            }else if('A' <= g[i][j] && g[i][j] <= 'Z')
                if(sm.count(g[i][j] )){
                    int tx = sm[g[i][j]].first, ty = sm[g[i][j]].second;
                    ma[{i, j}] = {tx, ty};
                    ma[{tx, ty}] = {i, j};
                }else sm[g[i][j]]={i, j};
        }
    bfs(begx, begy);
    cout<<r<<endl;
    return 0;
}
