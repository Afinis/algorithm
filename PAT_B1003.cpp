#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		string s; cin>>s; 
		int l = s.size(), en = 0, np=0, nt=0, other=0, lp=-1, lt=-1;		
		for(int j = 0; j < l; j++)
			if(s[j]=='P'){
				np++;
				lp=j;
			}else if(s[j]=='T'){
				nt++;
				lt=j;
			}else if(s[j]!='A') other++;
		if(other || nt != 1 || np != 1 || lt-lp<=1){
			cout<<"NO"<<endl;
			continue;
		}
		int x = lp, y = lt-lp-1, z = l - lt - 1;
		x == z-x*(y-1) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
	return 0;
}
