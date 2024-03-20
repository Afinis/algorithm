#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7, MOD = 998244353;
ll v[N+10], c[N+10], n, m, minV, maxV, sumV, notExit[N+10], num;

struct cmp1{
	bool operator()(ll a, ll b){
		return v[a] > v[b];
	}
};

struct cmp2{
	bool operator()(ll a, ll b){
		return v[a] < v[b];
	}
};

priority_queue<ll, vector<ll>, cmp1> sq;
priority_queue<ll, vector<ll>, cmp2> bq;

int main(){
	scanf("%lld%lld%lld", &n, &m, &maxV);
	for(ll i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		c[i]=1;
		sumV = (sumV+v[i])%MOD;
		sq.push(i);
		bq.push(i);
		num++;
	}
	while(m--){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		maxV -= x;
		minV -= x;
		if(x>0){
			sumV = (sumV+x*num)%MOD;		
			ll cSeg=0, cM=0;
			while(!bq.empty()){
				ll i = bq.top();
				if(notExit[i]){
					bq.pop();
					continue;
				}
				if(v[i] <= maxV){
					break;
				}
				num = (num-c[i]+MOD)%MOD;
				bq.pop();
				notExit[i] = 1;
				cSeg = (cSeg+c[i]*(v[i]-maxV)%MOD)%MOD;
				cM = (cM+c[i])%MOD;
			}
			if(cSeg){
				v[n] = maxV, c[n] = cM; 
				bq.push(n); sq.push(n); 
				num = (num+cM)%MOD; n++;
				
				v[n] = minV+1, c[n] = cSeg;
				bq.push(n); sq.push(n); 
				num = (num+cSeg)%MOD; n++;
			}
			
		}else{
			while(!sq.empty()){
				ll i = sq.top();
				if(notExit[i]){
					sq.pop();
					continue;
				}
				if(v[i] > minV){
					break;
				}
				sumV = (sumV - c[i]*(v[i]-(minV+x))%MOD + MOD)%MOD;
				sq.pop();
				num = (num - c[i] + MOD)%MOD;
				notExit[i] = 1;	
			}
			sumV = (sumV + num*x%MOD + MOD)%MOD;
		}
		if(y){
			v[n] = y+minV, c[n] = 1;
			bq.push(n); sq.push(n);
			sumV = (sumV + y)%MOD;
			n++;
			num = (num+1)%MOD;
		}
		printf("%lld\n", sumV);
	}
	return 0;
}
