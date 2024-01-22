#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
string str;
int s,n,tot;
int a[100031];
int num[55][55];
int dp[55][100031];
bool z;

signed main(){
	cin>>str>>s;
	n=str.size();
	for(int i=0;str[i];i++){
		if(str[i]!='0') z=1;
		if(z) a[++tot]=str[i]-'0';
	}
	for(int i=1;i<=tot;i++){
		num[i][i]=a[i];
		for(int j=i;j-i<=11&&j<=tot;j++)
			num[i][j]=num[i][j-1]*10+a[j];
	}
	for(int i=0;i<=tot+1;i++)
	    for(int j=0;j<=s+1;j++)
	        dp[i][j]=0x7fffffff;
	dp[0][0]=0;
	for(int i=1;i<=tot;i++)
		for(int k=1;k<=11;k++)
			if(i>=k)
				for(int j=num[i-k+1][i];j<=s;j++)
					dp[i][j]=min(dp[i][j],dp[i-k][j-num[i-k+1][i]]+1);
	if(dp[tot][s]>tot) cout<<-1;
	else cout<<dp[tot][s]-1;
	return 0;
}
