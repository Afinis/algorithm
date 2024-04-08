#include<bits/stdc++.h>
using namespace std;
int ans, m[15], d[50];
string s[6];
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int smh(int i){
	if(s[i].find('*')!=-1){
		if(i==2) return 24;
		return 60;
	}else if(s[i].find('-')!=-1){
		int p = s[i].find('-');
		string a = s[i].substr(0, p);
		string b = s[i].substr(p+1);
		return atoi(b.c_str())-atoi(a.c_str())+1;
	}else if(s[i].find(',')!=-1){
		int c = 0, p = 0;
		while(true){
			p = s[i].find(',', p+1);
			if(p==-1) break;
			c++;
		}
		return c+1;
	}else{
		return 1;
	}
}


void DAY(int i){
	if(s[i].find('*')!=-1){
		for(int i = 1; i <= 31; i++){
			d[i] = 1;
		}
	}else if(s[i].find('-')!=-1){
		int p = s[i].find('-');
		string a = s[i].substr(0, p);
		string b = s[i].substr(p+1);
		int x=atoi(a.c_str()), y=atoi(b.c_str());
		for(int i = x; i <= y; i++){
			d[i] = 1;
		}
	}else if(s[i].find(',')!=-1){
		int p = 0, pre=-1;
		while(true){
			p = s[i].find(',', p+1);
			int x = atoi(s[i].substr(pre+1, p-pre).c_str());
			d[x] = 1;
			pre = p;
			if(pre==-1) break;
		}
	}else{
		d[atoi(s[i].c_str())] = 1;
	}
}

void MON(int i){
	if(s[i].find('*')!=-1){
		for(int i = 1; i <= 12; i++){
			m[i] = 1;
		}
	}else if(s[i].find('-')!=-1){
		int p = s[i].find('-');
		string a = s[i].substr(0, p);
		string b = s[i].substr(p+1);
		int x=atoi(a.c_str()), y=atoi(b.c_str());
		for(int i = x; i <= y; i++){
			m[i] = 1;
		}
	}else if(s[i].find(',')!=-1){
		int p = 0, pre=-1;
		while(true){
			p = s[i].find(',', p+1);
			int x = atoi(s[i].substr(pre+1, p-pre).c_str());
			m[x] = 1;
			pre = p;
			if(pre==-1) break;
		}
	}else{
		m[atoi(s[i].c_str())] = 1;
	}
}

int main(){
	for(int i = 0; i < 5; i++){
		cin>>s[i];
	}
	int a = smh(0)*smh(1)*smh(2);
	int D = 1, M = 1;
	DAY(3);
	MON(4);
	while(M<=12&&D<=31){
		if(m[M]&&d[D]) ans++;
		D++;	
		if(D>mon[M]){
			D=1;
			M++;
		}
	}
	cout<<ans*a<<endl;
	return 0;
}
