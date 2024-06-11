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
	// ����ջ 
	fill(l, l+N, -1); //��ʼ�� 
	for(ll i = 0; i < n; i++){
		while(!s.empty() && a[s.back()] >= a[i]){
			s.pop_back();
		}
		// ��ʱa[ջ��Ԫ��]С��a[i] ����Ϊa[i]��ߵ�һ��С��a[i]��Ԫ�� 
		if(!s.empty())
			l[i] = s.back();
		s.push_back(i);
	}
	s.clear(); 
	// ����ջ
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
