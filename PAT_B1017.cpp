#include<bits/stdc++.h>
using namespace std;

struct bign{
	int d[1005]; //�����ĵ�λ�洢������ĵ�λ 
	int len;
	
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	} 
}; 

// ��ֵ 
bign change(char s[]){
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++){
		a.d[i] = s[a.len - i - 1] - '0';
	}
	return a;
}

// �ȴ�С
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
		int t = r*10 + a.d[i]; // ��ʱ�ı����� 
		r = t % b;
		a.d[i] = t/b;
	}
	// �Ƴ���λǰ���0 
	while(a.len > 1 && a.d[a.len-1] == 0)
		a.len--;
	return a;
}


int main(){
	char a[1005] ; int b, r=0;
	scanf("%s %d", a, &b);
	bign c = change(a); 
	c = divide(c, b, r);
	for(int i = c.len-1; i >= 0; i--){
		printf("%d", c.d[i]);
	}
	printf(" %d", r);
	return 0;
}
