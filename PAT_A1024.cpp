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


bign multi(bign a, int b){
	int r = 0; //��λ 
	bign c;
	for(int i = 0; i < a.len; i++){
		int t = a.d[i] * b + r;
		c.d[c.len++] = t%10;
		r =  t/10;
	}
	while(r){ // �ͼӷ���һ�����˷��Ľ�λ���ܲ�ֹһλ 
		c.d[c.len++] = r%10;
		r /= 10;
	}
	return c;
}
bign add(bign a, bign b){
	int r = 0, l = max(a.len, b.len); //r��λ 
	bign c;
	for(int i = 0; i < l; i++){
		int t = a.d[i] + b.d[i] + r;
		c.d[c.len++] = t%10;
		r = t / 10;
	}
	if(r) c.d[c.len++] = r; // ���н�λ���������λ 
	return c;
}

bign sub(bign a, bign b){
	// assert: a >= b
	bign c;
	int r = 0, l = max(a.len, b.len); //r��λ 
	for(int i = 0; i < l; i++){
		if(a.d[i] < b.d[i]){
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	// �Ƴ���λǰ���0 
	while(c.len > 1 && c.d[c.len-1] == 0) c.len--;
	return c;
}

int main(){
	char a[1005]; int k;
	scanf("%s %d", a, &k);
	bign c = change(a); 
	int i;
	for(i = 0; i < k; i++){ 
		bign d = c; 
		reverse(d.d, d.d+d.len);
		if(compare(c, d)==0) break;
		c = add(c, d);
	}
	for(int i = c.len-1; i >= 0; i--) printf("%d", c.d[i]);
	printf("\n%d", i);
	return 0;
}
