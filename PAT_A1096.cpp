#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n; scanf("%lld", &n);
	ll sqr = (ll)sqrt(n), p = 0, r = 0;
	for(int i = 2; i <= sqr; i++){
		ll t = 1, j = i;
		while(1){
			t *= j;
			if(n%t !=0 ) break;
			if(j-i+1 > r){
				p = i;
				r = j-i+1;
			}
			j++;
		}
	}
	if(r==0) printf("1\n%lld", n);
	else{
		printf("%lld\n", r);
		for(ll i = 0; i < r; i++){
			if(i != 0) printf("*");
			printf("%lld", p+i);
		}
	}
	return 0;
}
