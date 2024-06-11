#include<bits/stdc++.h>
using namespace std;
int g[10][10] = { 
	{1,1,0,1,0,1,1,1,1,1}, 
	{1,1,1,0,0,1,1,1,1,0}, 
	{1,1,0,0,1,0,1,1,1,1}, 
	{1,0,1,1,0,1,1,1,1,0}, 
	{1,0,1,0,1,1,1,1,0,0}, 
	{1,0,0,1,0,1,0,1,0,1}, 
	{1,1,1,1,1,1,1,1,1,0}, 
	{0,1,1,1,1,1,1,1,1,0}, 
	{0,1,1,0,1,0,1,1,1,1}, 
	{1,0,1,0,0,1,0,1,0,0} 
};
unordered_map<int, int > mp;

bool check(int x, int y){
	if(0<=x&&x<10&&0<=y&&y<10&&g[x][y]){
		return true;
	}
	return false;
}

int main(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(g[i][j]==0) continue;
			for(int x = i; x < 10; x++){
				for(int y = j; y < 10; y++){
					if(x==i && y==j) continue;
					if(g[x][y]==0) continue;
					int dx = x-i, dy = y-j;
					if(check(i+dy, j-dx) && check(i+dy+dx, j-dx+dy)){
						mp[dx*dx+dy*dy]++;
					}
				}
			}
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
