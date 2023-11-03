#include<bits/stdc++.h>
using namespace std;

int n,m,l, tim[1000+5], key[100000 + 5];

struct node{
	int ca=0;
	int end = 0;
	queue<int > q;
} e[10000+5];


void clea(){
	int p = -1, lo = 110000;
	for(int j = 1; j <= m; j++){
		if(!e[j].q.empty()){
			if(e[j].end < lo){
				lo = e[j].end;
				p = j;
			}else if(p != -1 && e[j].end == lo && e[j].q.front() < e[p].q.front()){
				lo = e[j].end;
				p = j;
			}
			
		}
	}
	if(p != -1){
		int t = e[p].q.front();
		e[p].q.pop();
		printf("%d:%d", t, e[p].end);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &l);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &tim[i]);
	}
	for(int i = 1; i <= l; i++){
		scanf("%d", &key[i]);
	}
	
	int i;
	for(i = 1; i <= m; i++){
		if(i <= l){
			e[i].ca++;
			e[i].q.push( i);
			e[i].end = tim[key[i]];	
		}
	}
	
	for(i; i <= l; i++){	
		clea();
		printf(" ");
		int p = -1, lo = 1100000;
		for(int j = 1; j <= m; j++){
			if(e[j].q.empty()){
				p = j;
				lo=0;
				break;
			}
			if(e[j].end < lo){
				lo = e[j].end;
				p = j;
			}else if(e[j].end == lo && j < p){
				lo = e[j].end;
				p = j;
			}
		}
		e[p].q.push(i);
		e[p].ca++;
		e[p].end+=tim[key[i]];
	}
	
	for(i = 1; i <= m; i++){
		if(i <= l){
			clea();
			if((i != m && l >= m) || (i != l && l < m)){
				printf(" ");
			}
			
		}
	}
	
	printf("\n");
	for(i = 1; i <= m; i++){
		printf("%d", e[i].ca);
		if(i != m){
			printf(" ", e[i].ca);
		}
	}
	
	return 0;
} 
