#include<bits/stdc++.h>
using namespace std;
const int n = 2021;
int a[15];
int main(){
	bool en = true;
	int i;
	for(i = 1; en ; i++){
		int t = i;
		while(t){
			if(a[t%10]==n){
				en=false;
				break;
			}
			a[t%10]++;
			t/=10;
		}
	}
	cout<<i-2<<endl;
	return 0;
}
