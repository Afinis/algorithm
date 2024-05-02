#include<bits/stdc++.h>
using namespace std;
const int n = 5;
unordered_map<string, int> mp;

bool check_row(int x, string  s){
	int ca = 0, cb = 0;
	for(int y = 0; y < n; y++){
		if(s[x*n+y] == '0'){
			ca++;
		}else{
			cb++;
		}
	}
	return !(ca==5||cb==5);
}

bool check_col(int y, string  s){
	int ca = 0, cb = 0;
	for(int x = 0; x < n; x++){
		if(s[x*n+y] == '0'){
			ca++;
		}else{
			cb++;
		}
	}
	return !(ca==5||cb==5);
}

bool check_k(string  s){
	int ca = 0, cb = 0;
	for(int i = 0; i < n; i++){
		if(s[i*n+i] == '0'){
			ca++;
		}else{
			cb++;
		}
	}
	return !(ca==5||cb==5);	
}

bool check_k2(string  s){
	int ca = 0, cb = 0;
	for(int i = 0; i < n; i++){
		if(s[i*n+(n-i-1)] == '0'){
			ca++;
		}else{
			cb++;
		}
	}
	return !(ca==5||cb==5);	
}

void dfs(int x, int y, string  s, int ca, int cb){
	if(x == 5){
		if(!check_k2(s) || !check_k(s)){
			return ;
		}
		for(int i = 0; i < n; i++){
			if(!check_col(i, s)){
				return;
			}
		}
		mp[s]++;
		return ;
	}
	if(y < 4){
		if(ca){
			dfs(x, y+1, s+"0", ca-1, cb);
		}
		if(cb){
			dfs(x, y+1, s+"1", ca, cb-1);
		}
	}else {	
		if(ca && check_row(x, s+"0")){			
			dfs(x+1, 0, s+"0", ca-1, cb);	
		}
		if(cb && check_row(x, s+"1")){
			dfs(x+1, 0, s+"1", ca, cb-1);
		}
	}
}


int main(){	
	dfs(0, 0, "", 13, 12);
	cout<<mp.size()<<endl; // 3126376
	return 0;
}
