#include<bits/stdc++.h>
using namespace std;

struct node{
	int h, m, s;
};

int mins(node x, node y, int d){
	return x.s-y.s + (x.m-y.m)*60 + (x.h-y.h)*60*60 + d*24*3600;
}

void OUT(int t){
	int s = t%60;
	t/=60;
	int m = t%60;
	t/=60;
	int h = t;
	printf("%02d:%02d:%02d\n", h, m, s);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		if(i==1){
			int pp = 0;
		}
		node a, b;
		int t1=-1, t2=-1;
		for(int j = 0; j < 2; j++){
			scanf("%d:%d:%d %d:%d:%d",&a.h,&a.m,&a.s,&b.h,&b.m,&b.s);
			char c = getchar();
			int d = 0;
			if(c==' '){
				scanf("(+%d)", &d);
			}
			if(t1<0) t1 = mins(b, a, d);
			else t2 = mins(b, a, d);
		}
		OUT((t2+t1)/2); 
	} 
	
	return 0;
}
