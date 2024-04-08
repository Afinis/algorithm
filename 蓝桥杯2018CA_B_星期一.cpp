#include<bits/stdc++.h>
using namespace std;

int M[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool run(int y){
	return (y%4==0&&y%100!=0) || (y%400==0);
}

int main(){
	// 36524
	int y = 1901, m = 1, d = 1, wek = 2, c = 0 , ans=0;
	while(!(y==2000&&m==12&&d==31)){
		c++;
		d++;
		wek++;
		if(wek>7){
			wek=1;
		}
		if(wek==1){
			ans++;
		}
		if(m==2){
			if((d>29&&run(y)) || (d>28&&!run(y)) ){
				d=1;
				m++;
			}
		}else if(d > M[m]){
			d=1;
			m++;
		}
		
		if(m > 12){
			m=1;
			y++;
		}
	}
	cout<<c<<endl;
	cout<<ans<<endl; // 5217
	return 0;
}
