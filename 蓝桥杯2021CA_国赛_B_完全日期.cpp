#include<bits/stdc++.h>
using namespace std;
int M[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans = 0;
bool run(int y){
	return (y%100!=0 && y%4==0) || (y%400==0);
}

int sumx(int x){
	int t = 0;
	while(x){
		t += (x%10);
		x /= 10;
	}
	return t;
}

bool check(int y, int m, int d){
	int t = sumx(y) + sumx(m) + sumx(d);
	int sq = sqrt(t);
	return t == sq*sq;
}

int main(){
	int y = 2001, m = 1, d= 1;
	while(true){
		d++;
		if(m==2 && d>29 && run(y)){
			d=1;
			m++;
		}else if(d > M[m]){
			d=1;
			m++;
		}
		if(m > 12){
			m=1;
			y++;
		}
		if(check(y, m, d)){
			ans++;
		}
		if(y==2021&&m==12&&d==31){	
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
