#include<bits/stdc++.h>
using namespace std;
const int y2=9999, m2=12, d2=31;
int ans, ya=1900, m1=1, d1=1;
int M[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool contwo(int x){
	while(x){
		if(x%10==2) return true;
		x /= 10;
	}
	return false;
}

bool check(int y, int m, int d){
	return contwo(y) || contwo(m) || contwo(d);
}

int main(){
	while(!(ya==y2&&m1==m2&&d1==d2)){
		if(check(ya, m1, d1)){
			ans++;
		}
		d1++;
		if(m1==2 && ((ya%4==0&&ya%100!=0) || ya%400==0)){
			if(d1 > 29){
				d1=1;
				m1++;
			}
		}else if(d1 > M[m1]){
			d1=1;
			m1++;
		}
		if(m1 > 12){
			ya++;
			m1=1;
		}
	}
	if(check(y2, m2, d2))
		ans++;
	cout<<ans<<endl; // 1994240
	return 0;
}
