#include <bits/stdc++.h>
using namespace std;
int e[105];
vector<int> v;
map<int, int> m;
int main(){
	int k = 0;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int t; scanf("%d", &t);
		e[i]=t;
		while (t!=1)
			if(t % 2 ==1){
				t = (3*t+1)/2;
				m[t]++;
			}else{
				t = t/2;
				m[t]++;
			}
	}
	for(int i = 0; i < k; i++)
		if(m[e[i]]==0) v.push_back(e[i]);
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < v.size(); i++){
		if(i) printf(" ");
		printf("%d", v[i]);
	}
	return 0;
}
