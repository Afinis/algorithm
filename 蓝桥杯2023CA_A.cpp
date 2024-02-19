#include<bits/stdc++.h>
using namespace std;
bool lucky(int x){
	string s = to_string(x);
	int c = s.size();
	if(c % 2) return false;
	int a = 0, b = 0, i = c/2;
	a = accumulate(s.begin(), s.begin()+i, 0);
	b = accumulate(s.begin()+i, s.end(), 0);
	return a == b ? true : false;
}
bool lucky2(int x){
	int c = to_string(x).size();
	if(c % 2) return false;
	int a = 0, b = 0, i = c/2;
	for(int j = 1; j <= c; j++){
		j <= i ? a += x%10 : b += x%10;
		x /= 10;
	}
	return a == b ? true : false;
}

int main(){
//	lucky(2314);
	int r = 0;
	for(int i = 1; i <= 100000000; i++){
		if(lucky2(i)) r++;
	}
	cout<<r<<endl;
	return 0;
}
