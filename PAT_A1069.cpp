#include<bits/stdc++.h>
using namespace std;

void ab(int &a, int &b, string s){
	while(s.size()<4) s+="0";
	sort(s.begin(), s.end());
	a = 0, b = 0;
	for(int i = 0; i < s.size(); i++) a = a*10 + s[i]-'0';
	for(int i = s.size()-1; i >= 0; i--) b = b*10 + s[i]-'0';
}
int main(){
	string n; cin>>n;
	int a,b;
	ab(a, b, n);
	while(b-a!=6174 && b-a!=0){
		//按格式输出 
		cout<<setfill('0')<<setw(4)<<b<<" - "<<setfill('0')<<setw(4)<<a
		<<" = "<<setfill('0')<<setw(4)<<b-a<<endl;
		ab(a,b,to_string(b-a));
	}
	cout<<setfill('0')<<setw(4)<<b<<" - "<<setfill('0')<<setw(4)<<a
		<<" = "<<setfill('0')<<setw(4)<<b-a<<endl;
	return 0;
}
