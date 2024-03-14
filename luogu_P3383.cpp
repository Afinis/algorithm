#include<bits/stdc++.h>
using namespace std;
const int M = 1e8+10;
int n, q, notP[M], p[M], pc;
/*
唯一分解定理： 
每个合数可用其最小因子和最大因子的乘积表示出来，且唯一
*/ 
void Euler(){
	for(int i = 2; i < n; i++){
		if(!notP[i])
			p[pc++] = i;
		// 枚举最小因子 p[j]，i为最大因子 
		for(int j = 0; j < pc && p[j] * i <= n; j++){
			notP[p[j]*i] = 1;
			/* 线性筛的核心： 
			 当p[j]为i的最小因子时退出循环， 
			 因为当p[j]大于i的最小因子时，
			 p[j]*i的最小因子存在于i的分解中。 */ 
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
