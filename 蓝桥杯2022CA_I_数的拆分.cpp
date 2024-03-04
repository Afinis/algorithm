#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sqn = 1e4;
int t, p[sqn+5], prim[sqn+5], cp;
ll a[100000+5];

void findPrim(){
	for(ll i = 2; i <= sqn; i++)
		if(p[i]==0){
			prim[cp++]=i;
			for(int j = i; j <= sqn; j+=i)
				p[j]=1;
		}
}

int odd, cf;
struct fac{
	ll x, cnt;
}f[100];

bool deFac(ll x){
	for(ll i = 0; i < cp; i++){
		ll t = prim[i];
		if(x%t==0){
			f[cf].x=t;
			while(x%t==0){
				f[cf].cnt++;
				x /= t;
			}
			if(f[cf].cnt==1) return false;
			cf++;
		}
	}
	if(x != 1){
		ll t = sqrt(x);
		if(t*t==x) return true;
		t = cbrt(x); //开三次方 		
		if(t*t*t==x||(t-1)*(t-1)*(t-1)==x||(t+1)*(t+1)*(t+1)==x) 
			return true;		
/*		t = pow(x, 1/3.0);
		if(t*t*t==x||(t-1)*(t-1)*(t-1)==x||(t+1)*(t+1)*(t+1)==x) 
			return true;*/
		return false;
	}
	return true;
}

int main(){
	findPrim();
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < t; i++){
		if(i==1)
			int ppp = 3;
		odd = cf = 0;
		memset(f, 0, sizeof(f));
		if(deFac(a[i]))
			printf("yes\n");
		else
			printf("no\n");	
	}
	return 0;
}
