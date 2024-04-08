#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int y[] = {0, 2, 0, 2, 3}, a[105];
int M[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check_d(string dat){
	int d = dat[7]-'0' + (dat[6]-'0')*10;
	int m = dat[5]-'0' + (dat[4]-'0')*10;
	return 1 <= d && d <= M[m];
}

bool check_m(string dat){
	int m = dat[5]-'0' + (dat[4]-'0')*10;
	return 1 <= m && m <= 12;
}

void dfs(int i, int k , string dat){
	if(i >= 100) return;
//	cout<<dat<<endl;
	if(k==8){
		if(check_d(dat)){
			mp[dat]++;
	//		cout<<dat<<endl;
		}
		return;
	}
	if(k <= 4){
		if(dat[k-1]-'0' != y[k]){
			return;
		}
	}
	if(k == 6){
		if(!check_m(dat)){
			return;
		}
	}
	string newdat = dat+char(a[i]+'0');
	dfs(i+1, k+1, newdat);
	dfs(i+1, k, dat);
} 

int main(){
	for(int i = 0; i < 100; i++)
		cin>>a[i];
	for(int i = 0; i < 100; i++){
		if(a[i]==2) dfs(i, 1, "2");
	}
	cout<<mp.size()<<endl;
	return 0;
}
