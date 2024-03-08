#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007, N=5e3+100;
char s[N], t[N];
ll dp[N][N], add[N], sum[N], l;

ll DP(){
	ll lc=0, rc=0, num=0;
	for(ll i = 1; i <= l; i++)
		if(s[i]=='(') lc++;
		else{
			rc++;
			if(lc){
				rc--;
				lc--;
			}
			add[++num]=rc;
		}	
	for(ll i = add[1]; i <= num; i++){
		dp[1][i] = 1;
		sum[i] = sum[i-1] + dp[1][i];
	}	
	for(ll i = 2; i <= num; i++){
		for(ll j = add[i]; j <= num; j++)
			dp[i][j]=(sum[j]-sum[add[i-1]-1]+MOD)%MOD;
		for(ll j = 0; j < add[i]; j++)
			sum[j] = 0;
		for(ll j = add[i]; j <= num; j++)
			sum[j] = sum[j-1]+dp[i][j];
	}
	return dp[num][add[num]];
}

void rever(){
	memset(dp,0,sizeof(dp));
    memset(add,0,sizeof(add));
    for(ll i=1;i<=l;i++) t[i]=(s[l-i+1]==')'?'(':')');
    for(ll i=1;i<=l;i++) s[i]=t[i]; 
}

int main(){
	scanf("%s", s+1);
	l = strlen(s+1);
	ll ans1 = DP();
	rever();
	ll ans2 = DP();
	if(!ans1) printf("%lld", ans2);
	else if(!ans2) printf("%lld", ans1);
	else printf("%lld", ans1*ans2%MOD);
	return 0;
}
