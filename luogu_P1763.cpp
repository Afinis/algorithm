#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, l, mi = 10000000+5;
vector<ll> r, v;

ll gcd(ll q, ll w){
	return q == 0 ? w : gcd(w%q, q);
}
void minu(ll &ta, ll &tb, ll c){
	ta = c*ta - tb;
	tb = c*tb;
	ll d = gcd(ta, tb);
	if(d != 0){
		ta /= d;
		tb /= d;
	}
}

bool dfs( ll ta, ll tb){
    ll last = v.empty() ? 0 : v[v.size()-1];
	if(v.size() == l && ta == 0){
		if(v[l-1] < mi ){
			mi = v[l-1];
			r = v;
		}
		return true;
	}
    ll rangeC = max((tb+ta-1)/ta, last+1);
    if (rangeC >= mi) return false;
	bool en = false, flag = false;
    if (l - v.size() == 2){
        for (ll k = (4*tb + ta*ta - 1)/(ta*ta);  ; ++k) { // k»°…œ’˚
            ll x, y;
            ll dert = ta*ta*k*k - 4 * tb * k;
            if (dert <= 0) continue;
            ll sq = sqrt((double )dert);
            y = (ta*k+sq);
            if (y >= mi*2) break;
            if (sq*sq == dert && y%2==0){
                x = (ta*k-sq)/2;
                y = (ta*k+sq)/2;
                if(y < mi){
                    mi = y;
                    r = v;
                    r.push_back(x);
                    r.push_back(y);
                    return true;
                }
            }
        }
        return false;
    }
	if(v.size() < l){
        ll t= (l - v.size())*tb/ta;
		for(ll c = rangeC; c <= t; c++){
			ll qa = ta, qb = tb;
			minu(qa, qb, c);
			if(qa >= 0 && qb >= 0){
				v.push_back(c);
				en = dfs(qa, qb);
                if (en) flag = true;
				v.pop_back();
			}
		}
	}
	return flag;
}
int main(){
	cin>>a>>b;
	for(l = 1; l; l++)
		if(dfs(a, b)){
			for(int i = 0; i < r.size(); i++){
				if(i != 0) cout<<" ";
				cout<<r[i];
			}
			return 0;
		}
	return 0;
}
