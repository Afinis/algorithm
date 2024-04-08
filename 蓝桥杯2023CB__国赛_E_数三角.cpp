#include <bits/stdc++.h>
using namespace std;
const int N=2005;
struct pnt
{
	int x,y;
};
int n,ans;
long long d;
float k;
pnt a[N];
int main()
{
	ios::sync_with_stdio(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	{
		unordered_map<long long,int> ma1;
		unordered_map<long long,map<float,int>> ma2;
		for(int j=1;j<=n;j++)
		{
			d=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y),k=INT_MAX;
			if(a[j].y!=a[i].y) k=float(a[i].x-a[j].x)/(a[i].y-a[j].y);
			ans+=(ma1[d]-ma2[d][k]);
			++ma1[d],++ma2[d][k];
		}
	}
	printf("%d",ans);
}
