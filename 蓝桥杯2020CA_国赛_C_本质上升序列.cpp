#include<bits/stdc++.h>
using namespace std;
string s;
int n;
// dp[i]：以字母i结尾的不同的子序列有多少个 
long long dp[30], ans;

int main(){
	//cin>>s;
	s = "tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	n = s.size();
	for(int i = 0; i < n; i++){
		int t = s[i]-'a';
		int r = 1;
		for(int j = 0; j < t; j++){
			r += dp[j];
		}
		dp[t] = r;
	}
	for(int i = 0; i < 27; i++){
	//	printf("dp[%d]=%d ", i, dp[i]);
		ans += dp[i];
	}
	cout<<ans<<endl; 
	return 0;
}
