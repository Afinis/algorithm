#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2000+10, M = 200, p = 1e9+7;

ll n, k;
ll nex[N][28], exist[N], cnt;
ll dp[N][M];

void insert(string s){
	ll p = 0;
	for(ll i = 0; i < s.size(); i++){
		ll c = s[i] - 'a';
		if(!nex[p][c]) nex[p][c] = ++cnt;
		p = nex[p][c];
	}
	exist[p] = 1;
}


ll t[N];
void dfs(ll u){
	if(exist[u]){
		dp[u][1] = 1;
		return ;
	}
	dp[u][0] = 1;
	for(ll i = 0; i < 26; i++){
		ll c = nex[u][i];
		if(c == 0) continue;
		dfs(c);
		fill(t, t+N, 0);
		for(int a = 0; a <= k; a++)
			for(int b = 1; a+b <= k; b++){
				t[a+b] = (t[a+b] + dp[u][a] * dp[c][b]) % p;
			} 
		for(int a = 0; a <= k; a++){
			dp[u][a] = t[a];
		}
	}
	if(u) dp[u][1]++;
}

int main(){
	cin>>n>>k;
	for(ll i = 0; i < n; i++){
		string s; cin>>s;
		insert(s);
	}
	dfs(0);		
	cout<<dp[0][k]%p<<endl;
	return 0;
}
