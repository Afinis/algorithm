#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e17;
ll T, n, m;
int l(int x){
    int c = 0;
    while(x){
        c++;
        x /= 10;
    }
    return c;
}

ll qpow(ll x, ll e){
    ll ans = 1, p = x;
    while(e){
        if(e&1){
            ans *= p;
        }
        p *= x;
        e>>=1;
    }
    return ans;
}

ll conv(ll x, ll h){
    if (h==0) return 1;
    ll ans = 0, p = 1;
    while(x){
        ans += x%10 * p;
        x /= 10;
        p *= h;
    }
    return ans;
}

int main(){
    cin>>T;
    for (ll j = 0; j < T; ++j) {
        ll i; cin>>n>>m;
        for (i = 1; ; ++i) {
            ll an = (m-1)* qpow(m, i-1)*i;
            if(n-an <= 0) break;
            n -= an;
        }
        ll t = n/i, k = n%i;
        ll num = qpow(10, i-1);
        num = conv(num, m);
        num += t;
        ll ans;
        if (k){
            k = i+1-k;
            while (k--){
                ans = num % m;
                num /= m;
            }
            cout<<ans<<endl;
        }else{
            cout<<(num-1)%m<<endl;
        }
    }
	return 0;
}
