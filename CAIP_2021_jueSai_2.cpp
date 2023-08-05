#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5+10;
ll a[maxn];
ll f[maxn], g[maxn];//长度为i的LIS结尾元素的最小值, 到i为止的LIS的长度最大值
ll ans = 0;
vector<ll>rp; //维护放R的数的下标
ll res[maxn]; //1为R，0为L

int main(){
	ll n;
	cin>>n;
	for(ll i = 1; i <= n; i++) cin>>a[i];
	for(ll i = 1; i <= n+1; i++){
		//枚举R开始的第一个点，跑LIS
		ll len = 0;
		for(ll j = i; j <= n; j++){
			if(len == 0){
				f[++len] = a[j];
				g[j] = len;
			}else {
				if(a[j] > f[len] ){
					f[++len] = a[j];
					g[j] = len;
				}else if(a[j] > f[1]){
					ll x = lower_bound(f+1, f+len+1, a[j]) - f;
					f[x] = a[j]; 
					g[j] = x;
				}
			}
		}
		vector<ll>tmp; //统计该LIS用了哪些数
		ll cnt = len, len1 = 0; 
		for(ll j = n; j >= 1; j--){
			if(g[j] == cnt && cnt){
				cnt--;
				tmp.push_back(j);
			}
			g[j] = 0;
		}
		sort(tmp.begin(),tmp.end());
		for(ll j = 0; j < tmp.size(); j++){
			res[tmp[j]] = 1;
		}		
		
		//剩余的[1,r-1]的数，即l部分，尝试续接上面的最LIS
		ll x = f[1]; //LIS的末位值，比他小就能接
        if(len==0)x = 1e18+10;
        for(ll j = n; j >= 1; j--){ // 往左插，下标顺序会反转 
            if(res[j]==1){
                res[j] = 0;  continue;
            }
            if(len1==0 && a[j]<x){
                f[++len1] = a[j];
            }else if(a[j] < x){
                if(a[j] > f[len1]){
                    f[++len1] = a[j];
                }else{
                    ll x = lower_bound(f+1, f+len1+1, a[j])-f;
                    f[x] = a[j];
                }
            }
        }
		
		//更新总的LIS答案
        if(len+len1 > ans){
            ans = len+len1;  rp = tmp;
        }else if(len+len1 == ans){//长度相同时取字典序更小的
            if(rp.size()==0)continue;
            if(tmp.size()==0)rp = tmp;
            else if(tmp > rp){
                rp = tmp;
            }
        }
	}
	
	cout<<ans<<"\n";
    for(ll i = 0; i < rp.size(); i++)res[rp[i]] = 1;
    for(ll i = 1; i <= n; i++){
        if(res[i])cout<<"R";else cout<<"L";
    }	
	return 0;
}
