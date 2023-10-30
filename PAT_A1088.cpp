#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
struct Fraction{
	ll a,b;
};
Fraction reduction(Fraction e){
	if(e.b < 0){
		e.a = -e.a;
		e.b = -e.b;
	}
	if(e.a == 0) e.b=1;
	else{
		int d = abs(gcd(e.a, e.b));
		e.a = e.a/d;
		e.b = e.b/d;
	}
	return e;
}
Fraction add(Fraction a, Fraction b){
	Fraction r;
	r.a = a.a*b.b + a.b*b.a;
	r.b = a.b * b.b;
	return reduction(r); 
}
Fraction minu(Fraction a, Fraction b){
	Fraction r;
	r.a = a.a*b.b - a.b*b.a;
	r.b = a.b * b.b;
	return reduction(r); 
}
Fraction mult(Fraction a, Fraction b){
	Fraction r;
	r.a = a.a * b.a;
	r.b = a.b * b.b;
	return reduction(r); 
}
Fraction divid(Fraction a, Fraction b){
	Fraction r;
	r.a = a.a * b.b;
	r.b = a.b * b.a;
	return reduction(r); 
}
void outp(Fraction e){
	if(e.b == 1)
		e.a < 0 ? printf("(%lld)", e.a) : printf("%lld", e.a);
	else if(abs(e.a) > abs(e.b))
		e.a < 0 ? printf("(%lld %lld/%lld)", e.a/e.b, abs(e.a%e.b), e.b) : printf("%lld %lld/%lld", e.a/e.b, abs(e.a%e.b), e.b);
	else e.a < 0 ? printf("(%lld/%lld)", e.a, e.b): printf("%lld/%lld", e.a, e.b);
}
int main(){
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.a, &a.b, &b.a, &b.b);
	outp(reduction(a)); printf(" + "); outp(reduction(b)); printf(" = "); outp(add(a,b)); printf("\n");
	outp(reduction(a)); printf(" - "); outp(reduction(b)); printf(" = "); outp(minu(a,b)); printf("\n");
	outp(reduction(a)); printf(" * "); outp(reduction(b)); printf(" = "); outp(mult(a,b)); printf("\n");
	if(b.a==0)
		outp(reduction(a)); printf(" / "); outp(reduction(b)); printf(" = Inf");printf("\n");
	else
		outp(reduction(a)); printf(" / "); outp(reduction(b)); printf(" = "); outp(divid(a,b));printf("\n");
	return 0; 
}
