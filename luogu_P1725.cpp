#include<bits/stdc++.h>
using namespace std;
const int MARX = 2e5 + 10;
int a[MARX], dp[MARX], n, l, r, ans = -100000000;
int que[MARX], head = 1, tail = 1; //��������, �ڲ�Ԫ��Ϊλ��

void insert(int i ){
	for(; dp[i] >= dp[que[tail]] && tail >= head; ){
		tail--; //����Ȩֵ�ͽ�С�� ��βԪ�� 
	}
	que[++tail] = i; //��� 
}
int query(int x)
{
	for(; que[head] + r < x; ) head++;//�������� ���ɵ���xλ�õ� ���Ϸ�Ԫ�� 
	return que[head];//�ش�ѯ�� 
}

int main(){
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 0; i <= n; i++){
		scanf("%d", &a[i]);
	}
	memset(dp, 128, sizeof(dp)); //��ʼ����Сֵ (ÿ���ֽڸ�128�ᵼ����Ȼ��� 
	dp[0] = 0;
	for(int i=l; i<=n ;i++){
		insert(i - l);  //�����һ�� �ܹ�ת�Ƶ�i��λ�� ���뵥������ 
		int from = query(i); //�ҵ����� Ȩֵ������λ�� 
		dp[i] = dp[from] + a[i];//����ת�� 
	}
	for(int i=n-r+1;i<=n;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
	return 0;
}
