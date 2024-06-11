#include<bits/stdc++.h>
using namespace std;
string s, ans;
int a, b;

void dfs(int k, int ca, int cb){
	if(k==s.size()){
		ans = max(ans, s);
		return;
	}
	int x = s[k] - '0';
	if(x== 9){
		dfs(k+1, ca, cb);
		return;
	}
	int t = x, tc = ca;
	while(true){
		if(t == 9 || tc ==a){
			break;
		}
		t++;
		if(t==10) t = 0;
		tc++;
	}
	s[k] = '0'+t;
	dfs(k+1, tc, cb);
	s[k] = '0'+x;
	
	t = x, tc = cb;
	while(true){
		if(t == 9 || tc ==b){
			break;
		}
		t--;
		if(t==-1) t = 9;
		tc++;
	}
	s[k] = '0'+t;
	dfs(k+1, ca, tc);
	s[k] = '0'+x;
}

int main(){
	cin>>s>>a>>b;
	ans = s;
	dfs(0, 0, 0);
	cout<<ans<<endl;
	return 0;
}
