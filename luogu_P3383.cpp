#include<bits/stdc++.h>
using namespace std;
const int M = 1e8+10;
int n, q, notP[M], p[M], pc;
/*
Ψһ�ֽⶨ�� 
ÿ��������������С���Ӻ�������ӵĳ˻���ʾ��������Ψһ
*/ 
void Euler(){
	for(int i = 2; i < n; i++){
		if(!notP[i])
			p[pc++] = i;
		// ö����С���� p[j]��iΪ������� 
		for(int j = 0; j < pc && p[j] * i <= n; j++){
			notP[p[j]*i] = 1;
			/* ����ɸ�ĺ��ģ� 
			 ��p[j]Ϊi����С����ʱ�˳�ѭ���� 
			 ��Ϊ��p[j]����i����С����ʱ��
			 p[j]*i����С���Ӵ�����i�ķֽ��С� */ 
			if(i%p[j]==0){
				break;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &q);
	Euler();
	for(int i = 0; i < q; i++){
		int t;
		scanf("%d", &t);
		printf("%d\n", p[t-1]);
	}
	return 0;
}
