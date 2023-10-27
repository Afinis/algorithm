#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
	scanf("%d", &n);
	int r = 0, l = 0, a = 1, now;
	while(n/a != 0){
		l = n/(a*10);
		now = n/a%10;
		r = n%a;
		if(now == 0) ans += (l * a);
		else if(now == 1) ans += l * a + r + 1;
		else ans += (l+1) * a;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}
