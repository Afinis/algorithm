#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
struct node{
	int ad, k,ne, order;
}a[N];
map<int, int> mm;
bool mycmp(node a, node b){
	return a.order < b.order;
}
int main(){
	int first, n;
	scanf("%d%d", &first, &n);
	for(int i = 0;i < n; i++){
		int ad, k, ne; scanf("%d%d%d", &ad, &k, &ne);
		a[ad].ad = ad;
		a[ad].k = k;
		a[ad].ne = ne;
	}
	for(int i = 0; i < N; i++) a[i].order = 2*N;
	int p = first, ca = 0, cb = 0;
	while(p != -1){
		if(mm.count((int)abs(a[p].k))){
			a[p].order = N + cb++;
		}else{
			mm[(int)abs(a[p].k)]++;
			a[p].order = ca++;
		}
		p = a[p].ne;
	}
	sort(a, a+N, mycmp);
	for(int i = 0; i < ca+cb; i++){
		if(i==ca-1 || i == ca+cb-1) printf("%05d %d -1\n", a[i].ad, a[i].k);
		else printf("%05d %d %05d\n", a[i].ad, a[i].k, a[i+1].ad);
	}
	return 0;
}
