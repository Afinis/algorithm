#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll g, m ,k, b;
long long ans;

ll toi(string s, ll p){
	ll sum=0;
	ll p1= s.find('[', p);
	for(ll p1= s.find('[', p); p1!=-1;  p1 = s.find('[', p1+1)){
		ll p2 = s.find(']', p1);
		ll num = atoi(s.substr(p1+1, p2-p1-1).c_str());
		sum+=num;
	}
	return sum;
}

ll type1Int(string s){
	ll sum=0;
	for(ll p= s.find('=', 0); p!=-1; p = s.find('=', p+1))
		sum++;
	return sum;
}
ll type1Str(string s){
	ll sum=0;
	for(ll p= s.find('=', 0); p!=-1; p = s.find('=', p+1)){
		ll p2 = s.find(',', p);
		if(p2==-1) p2 = s.find(';', p);
		sum+=p2-p-3;
	}
	return sum;
}
int main(){
	cin>>n;
	getchar();
	for(ll i = 0;i < n; i++){	
		char t[1500];
		gets(t);
		string s(t);
		if(s[0]=='i'&&s[3]=='['){
			ll sum=toi(s, 4);	
			ans += sum*4;
		}else if(s[0]=='l'&&s[4]=='['){
			ll sum=toi(s, 5);	
			ans += sum*8;
		}else if(s[0]=='S'&&s[6]=='['){
			ll sum=toi(s, 7);	
			ans += sum;
		}else if(s[0]=='i'){
			ll sum = type1Int(s);
			ans += sum*4;
		}else if(s[0]=='l'){
			ll sum = type1Int(s);
			ans += sum*8;
		}else if(s[0]=='S'){
			ll sum = type1Str(s);
			ans += sum;
		}
	}
	b = ans;
	if(b>=1024){
		k = b/1024;
		b = b%1024;
	}
	if(k>=1024){
		m = k/1024;
		k = k%1024;
	}
	if(m>=1024){
		g = m/1024;
		m = m%1024;
	}
	if(g) cout<<g<<"GB";
	if(m) cout<<m<<"MB";
	if(k) cout<<k<<"KB";
	if(b) cout<<b<<"B"<<endl;
	return 0;
}
