#include<bits/stdc++.h>
using namespace std;
const int MARX = 2e5 + 10;
int a[MARX], dp[MARX], n, l, r, ans = -100000000;
int que[MARX], head = 1, tail = 1; //单调队列, 内部元素为位置

void insert(int i ){
	for(; dp[i] >= dp[que[tail]] && tail >= head; ){
		tail--; //弹出权值和较小的 队尾元素 
	}
	que[++tail] = i; //入队 
}
int query(int x)
{
	for(; que[head] + r < x; ) head++;//弹出队首 不可到达x位置的 不合法元素 
	return que[head];//回答询问 
}

int main(){
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 0; i <= n; i++){
		scanf("%d", &a[i]);
	}
	memset(dp, 128, sizeof(dp)); //初始化极小值 (每个字节赋128会导致自然溢出 
	dp[0] = 0;
	for(int i=l; i<=n ;i++){
		insert(i - l);  //将最后一个 能够转移到i的位置 加入单调队列 
		int from = query(i); //找到队首 权值和最大的位置 
		dp[i] = dp[from] + a[i];//进行转移 
	}
	for(int i=n-r+1;i<=n;i++) ans=max(ans,dp[i]);
    printf("%d",ans);
	return 0;
}
