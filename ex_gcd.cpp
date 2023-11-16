#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

int exGcd(int a, int b, int &x, int &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	int g = exGcd(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - (a/b)*y;
	return g;
}

int main(){
	
	int a,b,c, x,y, g;
	cin>>a>>b; c = 1;
	g = exGcd(a, b, x, y);
	if(c%g != 0) cout<<"No Solution";
	else{
		x *= c/g;
		int t = abs((b/g));
		x = ((x%t) + t)%t;
		y = (c - a*x)/b;
		cout<< x;
	}
	return 0;
}
