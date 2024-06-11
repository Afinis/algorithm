#include<bits/stdc++.h>
using namespace std;
int M[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans; 
bool check(int x){
	while(x){
		if(x%10==1) return true;
		x /= 10;
	}
	return false;
}

int main(){
	int m = 1, d = 1, w = 7;
	while(!(m==13)){
		if(check(m) || check(d) || check(w)){
			ans += 5;
		}else{
			ans++;
		}
		
		d++;
		if(d > M[m]){
			d = 1;
			m++;
		}
		w++;
		if(w==8) w = 1;
	}
	cout<<ans<<endl;
	return 0;
}
