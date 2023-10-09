#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node{
	char name[10];
	int age;
	int worth;
}p[N+5];
bool mycmp(node a, node b){
	if(a.worth == b.worth ){
		if(a.age == b.age) return strcmp(a.name, b.name) < 0;
		else return a.age < b.age;
	}else return a.worth > b.worth;
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		char na[10];
		int age, worth;
		scanf("%s%d%d", na ,&age, &worth);
		strcpy(p[i].name, na);
		p[i].age = age;
		p[i].worth = worth;
	}
	sort(p, p+n, mycmp);
	for(int i = 0; i < k; i++){
		int c, lo, hi;
		scanf("%d%d%d", &c, &lo, &hi);
		int oldc = c;
		printf("Case #%d:\n", i+1);
		int t = n;
		for(int j = 0; j < n && c; j++)
			if(lo <= p[j].age && p[j].age <= hi){
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				c--;
			}
		if(c == oldc) printf("None\n");
	}
	return 0;
}
