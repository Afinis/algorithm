#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int[5]> mp;
unordered_map<string, vector<int> > r;
int kf, kb, en, cf[15], cb[15];
vector<int> a, b;
string add_s(string s, int i, int ad){
	int t = (s[i]-'0'+ad)%4;
	s[i] = t == 0 ? '4' : '0' + t;
	return s;
}
string minus_s(string s, int i, int ad){
	int t = (s[i]-'0'-ad+4)%4;
	s[i] = t == 0 ? '4' : '0' + t;
	return s;
}
void dfs_forward(int d, string now, int i, vector<int> &v){
	if(d == kf) r[now] = v;
	if(d >= kf || i > 12) return;
	dfs_forward(d, now, i+1, v);
	if(cf[i] < 3){
		v.push_back(i); cf[i]++;
		int ne = mp[i][now[i] - '0'];
		now = add_s(now, i, 1);
		string s = add_s(now , ne, 1);
		dfs_forward(d+1, s, 1, v);
		v.pop_back();
		cf[i]--;
	}
}
void dfs_backward(int d, string now, int i, vector<int> &v){
	if(en) return;
	if(d == kb)				
		if(r.count(now)){
			en = 1;
			a = r[now];
			b = v;
		}
	if(d >= kb || i > 12) return;	
	dfs_backward(d, now, i+1, v);
	if(cb[i] < 3){
		v.push_back(i); cb[i]++;
		now = minus_s(now, i, 1);
		int ne = mp[i][now[i]-'0'];
		string s = minus_s(now, ne, 1);
		dfs_backward(d+1, s, 1, v);
		v.pop_back();
		cb[i]--;
	}
}
int main(){
	string beg = "0", ed = "0111111111111";
	for(int i = 1; i <= 12; i++){
		string t;
		cin>>t;
		beg += t;
		for(int j = 1; j <= 4; j++){
			cin>>mp[i][j];
		}
	}	
	int k = 1;
	while(en == 0){
		vector<int> v;
		kf = (k+1) / 2;
		kb = k / 2;
		dfs_forward(0, beg, 1, v);
		dfs_backward(0, ed, 1, v);
		k++;
	}
	cout<<k-1<<endl;
	for(int i = 0; i < a.size(); i++){
		if(i != 0) cout<<" ";
		cout<<a[i];
	}
	for(int i = b.size()-1; i >= 0; i--){
		cout<<" ";
		cout<<b[i];
	}
	return 0;
}
 
