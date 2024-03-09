#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
long long ans;
int id[M], pre[300][M], ne[300][M], n;
char s[M];
int main(){
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i = 1; i <= n; i++){
		if(id[s[i]]==0){
			id[s[i]]=i;
		}else{
			pre[s[i]][i] = id[s[i]];
			ne[s[i]][id[s[i]]] = i;
			id[s[i]]=i;
		}
	}
	for(int i = 1; i <= n; i++){
		if(ne[s[i]][i]==0) ne[s[i]][i]=n+1;
		ans+= (ne[s[i]][i]-i)*(i-pre[s[i]][i]);
	}
	printf("%lld\n", ans);
	return 0;
}
