#include<bits/stdc++.h>
using namespace std;
const int N = 23333333;
const double R = 11625907.5798, eps=1e-4;
double log2(double x){
	return log(x) / log(2);
}

bool equ(double a, double b){
	return  abs(a-R) <= eps;
}

int main(){
	for(int i = 1; i <= N; i++){
		double p1 = (double)(N-i)/N, p0 = (double)i/N;
		double log2P1 = log2(N-i)-log2(N);
		double log2P0 = log2(i)-log2(N);
		double r = (N-i)*p1*log2P1 + i*p0*log2P0;
		r=-r;
		if(equ(r, R)){
			cout<<i<<endl;// 11027421
			return 0;
		}
	}
	return 0;
}
