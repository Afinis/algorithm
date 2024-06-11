#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
string a, b;
int ba[30], ab[30], ans;

int mp(char x){
	return x-'a'+1;
}

int main(){
	cin>>a>>b;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			fill(ba, ba+30, 0);
			fill(ab, ab+30, 0);
			for(int k = 0; j+k < b.size() && i+k < a.size(); k++){
				char aa = a[i+k], bb = b[j+k];
				if(ba[mp(b[j+k])] == 0){
					ba[mp(b[j+k])] = mp(a[i+k]);
				}
				if(ab[mp(a[i+k])] == 0){
					ab[mp(a[i+k])] = mp(b[j+k]);
				}
				if(ba[mp(b[j+k])] != mp(a[i+k])){
					break;
				}
				if(ab[mp(a[i+k])] != mp(b[j+k])){
					break;
				}
				ans = max(ans, k+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
