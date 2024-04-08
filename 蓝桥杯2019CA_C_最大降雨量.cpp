#include<bits/stdc++.h>
using namespace std;
const int n = 49, M = 100000;
int a[50], b[10], cb, ans;

int mi(int lo, int hi, int * e){
	sort(e+lo, e+hi);
	int mi = lo+hi>>1;
	return e[mi];
} 

int main(){
	for(int i = 0; i < n; i++){
		a[i] = i+1;
	}
	for(int j = 0; j < M; j++){
		random_shuffle(a, a+n);
		cb=0;
		for(int i = 0; i < n; i+=7){
			b[cb] = mi(i, i+7, a);
			cb++;
		}
		ans = max(ans, mi(0, 7, b));
	}
	cout<<ans<<endl;
	return 0;
}
