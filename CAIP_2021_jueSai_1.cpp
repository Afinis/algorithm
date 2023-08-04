//7-1 ÂÌµØÎ§À¸
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PLL;

int n, l;
int x, y;
vector<PLL> ps;

int main(){
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		int u;
		cin >> u;
		if(i % 2 == 0) y = u;
		else x = u;
		ps.push_back({x, y});
	}
	
	x = 0, y = 0;
	int u = 0, i = 0;
	int px = ps[0].x, py = ps[0].y;
	
	ps.push_back({0, 0});
	cout << "0 0" << endl;
	
	while(i < ps.size()){
		if(u == l){
			if(x == 0 && y == 0) break;
			u = 0;
			cout << x << ' ' << y << endl;
		}
		
		if(x == px && y == py){
			i++;
			px = ps[i].x, py = ps[i].y;
			continue;
		}		
		u++;
		if(x == px)		
			if(y < py) y++;
			else y--;
		else
			if(x < px) x++;
			else x--;	
	}
	return 0;
} 

