#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5;
ll a[N], l[N], r[N], ans;

int main(){
	ll n; cin>>n;
	for(ll i = 0; i < n; i++){
		cin>>a[i];
	}
	deque<ll> s;
	// 单增栈 
	fill(l, l+N, -1); //初始化 
	for(ll i = 0; i < n; i++){
		while(!s.empty() && a[s.back()] >= a[i]){
			s.pop_back();
		}
		// 此时a[栈顶元素]小于a[i] 且其为a[i]左边第一个小于a[i]的元素 
		if(!s.empty())
			l[i] = s.back();
		s.push_back(i);
	}
	s.clear(); 
	// 单减栈
	fill(r, r+N, n); 
	for(ll i = n-1; i >= 0; i--){
		while(!s.empty() && a[s.back()] >= a[i]){
			s.pop_back();
		}
		if(!s.empty())
			r[i] = s.back();
		s.push_back(i);
	}
	ans = 0;
	for(ll i = 0; i < n; i++){
		ans = max(ans, (r[i]-l[i]-1)*a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
