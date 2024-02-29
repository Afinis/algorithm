#include<bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool check(string s){
	int c = 0;
	for(auto i : s)
		c += i == 'O';
	return c == 1;
}

bool dfs(string s){
	if(mp.count(s))
		return mp[s];
	if(check(s)){
		mp[s] = false;
		return false;
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'O'){
			string t = s;
			t[i] = 'X';
			if(dfs(t)==false){
				// 一个状态是必胜状态充要条件：至少一个必败状态为它的后继状态
				mp[s] = true;
				return true;
			}
		}
	}
	for(int i = 1; i < s.size(); i++){
		if(i != 4 && s[i]=='O' && s[i-1] == 'O'){
			string t = s;
			t[i]=t[i-1]='X';
			if(dfs(t) == false){
				mp[s] = true;
				return true;
			}
		} 
	}
	//没有后继状态的状态是必败状态
	//一个状态是必败状态充要条件：它的所有后继状态均为必胜状态 
	return false;
}

int main(){
	string a = "XOOOOOOO";
	string b = "XXOOOOOO";
	string c = "OXOOOOOO";
	string d = "OXXOOOOO";
	cout<<(dfs(a)? "L":"V");
	cout<<(dfs(b)? "L":"V");
	cout<<(dfs(c)? "L":"V");
	cout<<(dfs(d)? "L":"V");
	return 0;
}
