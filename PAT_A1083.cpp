#include <bits/stdc++.h>
using namespace std;
struct node{
	char name[15], id[15];
	int grade;
};
bool mycmp(node a, node b){
	return a.grade > b.grade;
}
vector<node> p;

int main(){
	int n, lo, hi;
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		char na[15], id[15]; int grade;
		scanf("%s %s %d", na, id, &grade);
		node t;
		strcpy(t.name, na);
		strcpy(t.id, id);
		t.grade=grade;
		p.push_back(t);
	}
	scanf("%d %d", &lo, &hi);
	sort(p.begin(), p.end(), mycmp);
	int c=0;
	for(int i = 0; i < n; i++)
		if(lo <= p[i].grade && p[i].grade <= hi){
			c++;
			printf("%s %s\n", p[i].name, p[i].id);
		}
	if(!c) printf("NONE\n");
	return 0;
}
