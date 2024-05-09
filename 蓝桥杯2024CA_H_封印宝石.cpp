#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, k;
int a[N], b[N];
set<pair<int, int> > s;

// Ä£Äâ±©Á¦ 

int main(){
	cin>>n>>k;	
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1, j = 0; i <= n; i++){
		while(j < n && j - i < k){
			++j;
			if(a[j] != -1) s.insert({-a[j], -j});
		}
		if(s.empty()){
			b[i] = -1;
			cout<<-1<<" "; 
		}else{
			int id = -s.begin()->second;
			if(a[id] != b[i-1]){
				cout<<a[id]<<" ";
				s.erase({-a[id], -id});
				b[i] = a[id];
				a[id] = -1;
				k -= id - i;
			}
		}
		s.erase({-a[i], -i});
		while(j-(i+1) > k){
			s.erase({-a[j], -j});
			--j;
		}
	}
	return 0;
} 
