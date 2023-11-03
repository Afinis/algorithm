/*
st数组表示加油站数组，先对st数组按距离排序，然后末尾添加哨兵节点，代表终点； 
贪心策略寻找下一个加油站：在自己能达到的范围内（c*v），
优先找比当前油价低的加油站，若找到，在当前加油站加足够的油前往； 
否则找范围内油价最低的加油站 ，在当前加油站加满油。 
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
	double p,d;
} st[505];
bool mycmp(node a, node b){
	return a.d < b.d;
}
int main(){
	double c,d,v, cnow=0, dnow = 0;
	int n, f=1;
	scanf("%lf%lf%lf%d", &c, &d,&v,&n);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf", &st[i].p, &st[i].d);
	sort(st, st+n, mycmp);
	st[n].p=0;
	st[n].d=d;
	n++;
	double q = c*v, r=0;
	for(int i = 0; i < n-1; ){
		if(st[0].d != 0){ //测试点2 
			f=0;
			dnow = 0;
			break; 
		}
		int ne=-1, en = 0;
		//寻找下一个加油站
		for(int j = i+1; j < n; j++){
			if(st[j].d - st[i].d > q) break; //在自己能达到的范围内（c*v）
			if(st[i].p > st[j].p){ //优先找比当前油价低的加油站
				ne = j;
				en = 1;
				break;
			}
			if(ne == -1 || st[ne].p > st[j].p) //否则找范围内油价最低的加油站
				ne = j;
		}
		if(ne == -1){ //油耗尽，无法到达 
			f=0;
			dnow = st[i].d += q;
			break;
		}
		if(en){
			if(cnow < (st[ne].d - st[i].d)/v){ //加足够的油 
				r+=((st[ne].d - st[i].d)/v - cnow)*st[i].p;
				cnow += (st[ne].d - st[i].d)/v - cnow;
			}
		}else{
			r+=(c-cnow)*st[i].p; //加满油 
			cnow = c;
		}
		cnow -= (st[ne].d - st[i].d)/v;
		i = ne;
	} 
	f ? printf("%.2f", r) : printf("The maximum travel distance = %.2f", dnow);
	return 0;
}
