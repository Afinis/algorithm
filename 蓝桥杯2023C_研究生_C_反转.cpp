#include<bits/stdc++.h>
using namespace std;
// Ì°ÐÄ 
int D; 
string s, t;
int main(){
	cin>>D;
	for(int i = 0; i < D; i++){
		cin>>t>>s;
		int n = s.size();
		int ans = 0;
		for(int j = 1; j < n-1; j++){
			if(s[j]!=t[j] && (s[j-1]==s[j+1]&&s[j-1]!=s[j])){
				ans++;
				s[j] = s[j+1];
			}
		}
		int en = 0;
		for(int j = 0; j < n; j++){
			if(s[j]!=t[j]){
				en = 1;
				break;
			}
		}
		if(en) cout<<-1<<endl; 
		else cout<<ans<<endl; 
	}
	return 0;
}
