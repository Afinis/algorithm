#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main(){
	cin>>a>>b;
	ll d = abs(b-a);
	ll k = (a+d)%d;
	cout<<d-k<<endl;
	
	return 0;
}
