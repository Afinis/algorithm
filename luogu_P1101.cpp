#include<bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, -1, -1, -1, 1, 1};
int Y[] = {1, -1, 0, 0, -1, 1, -1, 1};
int n, r[105][105];
char g[105][105];
string s = "yizhong";
void check(int x, int y, int f){
    int en = 1, oldx = x, oldy = y;
    for(int i = 0; i < 7; i++){
        if(x < 0 || x >= n || y < 0 || y >= n || s[i] != g[x][y]){
            en = 0;
            break;
        }
        x = x + X[f];
        y = y + Y[f];
    }
    if(en)
        for(int i = 0; i < 7; i++){
            r[oldx][oldy]++;
            oldx = oldx + X[f];
            oldy = oldy + Y[f];
        }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <n ; j++) cin>>g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <n ; j++)
            for(int f = 0; f < 8; f++) check( j, i, f);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n ; j++)
            r[i][j] ? cout<<g[i][j] : cout<<"*";
        cout<<endl;
    }
    return 0;
}
