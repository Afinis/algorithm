#include<bits/stdc++.h>
using namespace std;

struct bign{
	int d[1005]; //整数的低位存储在数组的低位 
	int len;
	
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	} 
}; 

// 赋值 
bign change(char s[]){
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++){
		a.d[i] = s[a.len - i - 1] - '0';
	}
	return a;
}

// 比大小
int compare(bign a, bign b){
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	else 
		for(int i = a.len-1; i >= 0; i-- ){
			if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
	return 0;	
}


bign divide(bign a, int b, int &r){
	r = 0;
	for(int i = a.len-1; i >= 0; i--){
		int t = r*10 + a.d[i]; // 临时的被除数 
		r = t % b;
		a.d[i] = t/b;
	}
	// 移除高位前面的0 
	while(a.len > 1 && a.d[a.len-1] == 0)
		a.len--;
	return a;
}


bign multi(bign a, int b){
	int r = 0; //进位 
	bign c;
	for(int i = 0; i < a.len; i++){
		int t = a.d[i] * b + r;
		c.d[c.len++] = t%10;
		r =  t/10;
	}
	while(r){ // 和加法不一样，乘法的进位可能不止一位 
		c.d[c.len++] = r%10;
		r /= 10;
	}
	return c;
}

int e[10];
int main(){
	char a[1005];
	scanf("%s", a);
	bign c = change(a); 
	for(int i = 0; i < c.len; i++) e[c.d[i]]++;
	c = multi(c, 2);	
	for(int i = 0; i < c.len; i++) e[c.d[i]]--;
	int en = 1;
	for(int i = 0; i < 10; i++)
		if(e[i]!=0){
			en = 0;
			break;
		}
	en ? printf("Yes\n") : printf("No\n");
	for(int i = c.len-1; i >= 0; i--) printf("%d", c.d[i]);
	return 0;
}
