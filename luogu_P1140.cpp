#include<bits/stdc++.h>
using namespace std;
int la, lb, dp[105][105];
string a, b;
unordered_map<char, int> s;
int g[][5] = { {5, -1, -2, -1, -3}, 
			   {-1, 5, -3, -2, -4},
			   {-2, -3, 5, -2, -2},
			   {-1, -2, -2, 5, -1},
			   {-3, -4, -2, -1, -100000000} };
int main(){
	cin>>la>>a>>lb>>b;
	s['A'] = 0;
	s['C'] = 1;
	s['G'] = 2;
	s['T'] = 3;
	s['-'] = 4;
	fill(dp[0], dp[0]+105*105, -10000);
	dp[0][0] = 0;
	for(int i = 0; i < la; i++){
		dp[0][i+1] = dp[0][i] + g[ s['-'] ][ s[b[i]] ];
		dp[i+1][0] = dp[i][0] + g[ s[a[i]] ][ s['-'] ];
	}
	for(int i = 0; i < la; i++){
		for(int j = 0; j < lb; j++){
			int pi = i+1, pj = j+1;
			dp[pi][pj] = max(dp[pi][pj], dp[pi-1][pj-1] + g[ s[a[i]] ][ s[b[j]] ]);
			dp[pi][pj] = max(dp[pi][pj], dp[pi-1][pj] + g[ s[a[i]] ][ s['-'] ]);
			dp[pi][pj] = max(dp[pi][pj], dp[pi][pj-1] + g[ s['-'] ][ s[b[j]] ]);
	//		printf("dp[%d][%d]=%d\n", pi, pj, dp[pi][pj]);
		}
	}
	cout<<dp[la][lb]<<endl;
	return 0;
}
