#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8;
const double eps = 1e-8;
struct node{
	int x, y;
};
vector<node> v;
bool equ(double a, double b){
	return abs(a-b) <= eps;
}
struct lin{
	double k, b;
	bool operator<(lin t)const{
		if(this->k != t.k){
			return this->k < t.k-eps;
		}else{
			return this->b < t.b-eps;
		}
	}
};
map<lin, int> mp;

int main(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 21; j++){
			node t;
			t.x = i, t.y = j;
			v.push_back(t);
		}
	}
	for(int i = 0; i < v.size(); i++){
		for(int j = i+1; j < v.size(); j++){
			if(i==j) continue;
			node u = v[i], w = v[j];
			lin t;
			if(u.x == w.x){
				t.k = inf;
				t.b = u.x;
			}else{
				t.k = (double)(u.y-w.y)/(u.x-w.x);
				t.b = u.y-t.k*u.x;
			}			
			mp[t]++;			
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
