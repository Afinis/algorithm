#include<bits/stdc++.h>
using namespace std;
int n,  cr[10000000], cc[10000000], sc[15];
string g[15];
bool check2(int x, int y){
    int r=1;
    for(int i = 1; y-i>=0 && g[x][y]==g[x][y-i]; i++){
        r++;
        if(r>2) return false;
    }
    r=1;
    for(int i = 1; x-i>=0 && g[x][y]==g[x-i][y]; i++){
        r++;
        if(r>2) return false;
    }
    return true;
}

bool check3_row(int x){
    int r = 0;
    for(int i = 0; i < n; i++){
        if(g[x][i]=='0'){
            r++;
        }
    }
    return r==n/2;
}
bool check3_col(int y){
    int r = 0;
    for(int i = 0; i < n; i++){
        if(g[i][y]=='0')
            r++;  
    }
    return r==n/2;
}
void dfs(int x, int y, int sr){
	if(x == n){
		for(int i = 0; i < n; i++){
			if(!check3_col(i) )
				return;		
		}
		for(int i = 0; i < n; i++)
			cc[sc[i]]++;
		int en = 0;
		for(int i = 0; i < n; i++){
			if(cc[sc[i]] > 1) en = 1;
			cc[sc[i]]=0;
		}
		if(en) return;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<g[i][j];
			cout<<endl;
		}
		exit(0);
	}
	if(g[x][y]=='_'){
		g[x][y]='1';
		int old = sc[y];
		sc[y] |= (1<<x);
		if(check2(x, y))
			if(y < n-1)
				dfs(x, y+1, sr|(1<<y) );
			else{
				int newsr = sr|(1<<y);
				if(!cr[newsr]&&check3_row(x) ){
					cr[newsr]++;
					dfs(x+1, 0, 1);
					cr[newsr]--;
				}
			}
		sc[y] = old;
		g[x][y]='0';
		if(check2(x, y))
			if(y < n-1)
				dfs(x, y+1, sr );
			else{
				if(!cr[sr]&&check3_row(x) ){
					cr[sr]++;
					dfs(x+1, 0, 0 );
					cr[sr]--;
				}
			}
		g[x][y]='_';
	}else{
		int old = sc[y];
		sc[y] |= ((g[x][y]-'0')<<x);
		if(check2(x, y))
			if(y < n-1)
				dfs(x, y+1, sr|((g[x][y]-'0')<<y) );
			else{
				int newsr = sr|((g[x][y]-'0')<<y);
				if(!cr[newsr]&&check3_row(x) ){
					cr[newsr]++;
					dfs(x+1, 0, g[x][y]-'0' );
					cr[newsr]--;
				}				
			}
		sc[y] = old;
	}
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>g[i];
    dfs(0, 0, 0);
    return 0;
}
