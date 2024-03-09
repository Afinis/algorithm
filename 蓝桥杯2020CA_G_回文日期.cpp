#include<bits/stdc++.h>
using namespace std;
string s;
const int M = 1e8;
int n;
int month[13][2] = {{0,0}, {31, 31}, {28,29}, 
{31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, 
{31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool isLeap(int y){
	return (y%4==0 && y%100)||(y%400==0);
}

bool check1(int x){
	if(x%10==x/10000000){
		x%=10000000;
		x/=10;
		if(x%10==x/100000){
			x%=100000;
			x/=10;
			if(x%10==x/1000){
				x%=1000;
				x/=10;
				if(x%10==x/10)
					return true;
			}
		}
	}
	return false;
}

bool check2(int x){
	int a = x%10, b = (x/10)%10;
	for(int i = 1; i <= 8; i++){
		if(i==5) swap(a,b);
		if((i%2 && x%10!=a) || (i%2==0 && x%10!=b)) 
			return false;
		x/=10;
	} 
	return true;
}



int main(){
	cin>>n;
	int d = n%100, m = (n/100)%100, y = n/10000;
	bool en1=true, en2=true;
	while(true){
		d++;
		if(d == month[m][isLeap(y)]+1){
			d=1;
			m++;
		}
		if(m==13){
			m=1;
			y++;
		}
		int now = y*10000+m*100+d;
		if(en1&&check1(now)){
			en1=false;
			cout<<now<<endl;
		}
		if(en2&&check2(now)){
			en2=false;
			cout<<now<<endl;
			return 0;
		}
	}
	return 0;
}
