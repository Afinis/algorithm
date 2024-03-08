#include<bits/stdc++.h>
using namespace std;

int n, lo=200, hi, t;
double avg; 
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>t;
		lo = min(lo, t);
		hi = max(hi, t);
		avg += t;
	}
	printf("%d\n%d\n%.2f\n", hi, lo, avg/n);
	return 0;
}
