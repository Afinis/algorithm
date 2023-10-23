#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, c=1;
struct node{
	int l,r;
} v[N];

bool mycmp(node a, node b){
	return a.l != b.l ? b.l < a.l : a.r < b.r;
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>v[i].l>>v[i].r;
	}
	sort(v, v+n, mycmp);
	int prel = v[0].l;
	for(int i = 1; i < n; i++){
		if(v[i].r <= prel){
			prel = v[i].l;
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}
