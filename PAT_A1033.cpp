/*
st�����ʾ����վ���飬�ȶ�st���鰴��������Ȼ��ĩβ����ڱ��ڵ㣬�����յ㣻 
̰�Ĳ���Ѱ����һ������վ�����Լ��ܴﵽ�ķ�Χ�ڣ�c*v����
�����ұȵ�ǰ�ͼ۵͵ļ���վ�����ҵ����ڵ�ǰ����վ���㹻����ǰ���� 
�����ҷ�Χ���ͼ���͵ļ���վ ���ڵ�ǰ����վ�����͡� 
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
		if(st[0].d != 0){ //���Ե�2 
			f=0;
			dnow = 0;
			break; 
		}
		int ne=-1, en = 0;
		//Ѱ����һ������վ
		for(int j = i+1; j < n; j++){
			if(st[j].d - st[i].d > q) break; //���Լ��ܴﵽ�ķ�Χ�ڣ�c*v��
			if(st[i].p > st[j].p){ //�����ұȵ�ǰ�ͼ۵͵ļ���վ
				ne = j;
				en = 1;
				break;
			}
			if(ne == -1 || st[ne].p > st[j].p) //�����ҷ�Χ���ͼ���͵ļ���վ
				ne = j;
		}
		if(ne == -1){ //�ͺľ����޷����� 
			f=0;
			dnow = st[i].d += q;
			break;
		}
		if(en){
			if(cnow < (st[ne].d - st[i].d)/v){ //���㹻���� 
				r+=((st[ne].d - st[i].d)/v - cnow)*st[i].p;
				cnow += (st[ne].d - st[i].d)/v - cnow;
			}
		}else{
			r+=(c-cnow)*st[i].p; //������ 
			cnow = c;
		}
		cnow -= (st[ne].d - st[i].d)/v;
		i = ne;
	} 
	f ? printf("%.2f", r) : printf("The maximum travel distance = %.2f", dnow);
	return 0;
}
