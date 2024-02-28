#include<bits/stdc++.h>
using namespace std;
int n, m, ans[15][15];
char g[15][15];

bool check(int x, int y){
	if(g[x][y]=='_')
		return true;
	int c = g[x][y] - '0';
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
			c -= ans[x+i][y+j];
	return c == 0;
}

void dfs(int x, int y){
	if(x == n+1){
		for(int i = 1; i <= m; i++){
			if(!check(n, i))
				return;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++)
				printf("%d", ans[i][j]);
			printf("\n");
		}
		exit(0);
	}
	if(y < m){
		ans[x][y] = 1;
		if(x < 2 || y < 2 || check(x-1, y-1))
			dfs(x, y+1);
		ans[x][y] = 0;
		if(x < 2 || y < 2 || check(x-1, y-1))
			dfs(x, y+1);
	}else if(x <= n){
		ans[x][y] = 1;
		if(x < 2 || (y == 1 && check(x-1, y)) || (check(x-1, y-1) && check(x-1, y)) )
			dfs(x+1, 1);
		ans[x][y] = 0;
		if(x < 2 || (y == 1 && check(x-1, y)) || (check(x-1, y-1) && check(x-1, y)) )
			dfs(x+1, 1);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
		for(int j = 1; j <= m; j++)
            g[i][j] = s[j-1];
	}
	dfs(1, 1);
    return 0;
}
