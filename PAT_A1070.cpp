#include<bits/stdc++.h>
using namespace std;
int n,d;
struct node{
	double in, p, per;
}ca[1000+5];
bool mycmp(node a, node b){
	return a.per > b.per;
}
int main(){
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%lf", &ca[i].in);
	for(int i = 0; i < n; i++){
		scanf("%lf", &ca[i].p);
		ca[i].per = ca[i].p / ca[i].in;
	}
	sort(ca, ca+n, mycmp);
	double r = 0;
	for(int i = 0; i < n; i++)
		if(d >= ca[i].in){
			d-=ca[i].in;
			r+=ca[i].p;
		}else{
			r+=ca[i].p*(d/(double)ca[i].in);
			break;
		}
	printf("%.2f", r);
	return 0;
}
