#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

struct Fraction{
	int up, down;
};

Fraction reduction(Fraction r){
	if(r.down < 0){ // 分母为负 
		r.up = -r.up;
		r.down = -r.down;
	}
	if(r.up == 0) r.down=1; // 0分数 
	else{ // 约分 
		int d = gcd(abs(r.up), abs(r.down)); // 使最大公约数>0 
		r.up /= d;
		r.down /= d;
	}
	return r;
}
// 加法 
Fraction add(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up*b.down + b.up*a.down;
	r.down = a.down * b.down;
	return reduction(r);
} 

// 减法 
Fraction minu(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up*b.down - b.up*a.down;
	r.down = a.down * b.down;
	return reduction(r);
} 

// 乘法
Fraction multi(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up * b.up;
	r.down = a.down * b.down;
	return reduction(r);
}

// 除法 
Fraction divide(Fraction a, Fraction b){
	Fraction r;
	r.up = a.up * b.down;
	r.down = a.down * b.up;
	return reduction(r);
}

void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1) printf("%d", r.up);
	else if(abs(r.up) > r.down){
		printf("%d %d/%d", r.up/r.down, r.up%r.down, r.down );
	}else{
		printf("%d/%d", r.up , r.down);
	}
} 

int main(){
	Fraction a, b, r;
	scanf("%d%d%d%d",&a.up ,&a.down ,&b.up ,&b.down);
	a = add(a, b);
	showResult(a);
	return 0;
}
