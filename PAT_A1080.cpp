/*
排名：最终成绩，笔试；笔试、总分相同，排名一致 
排名一致的学生，所报学校必须录取 
输出：一行一个学校，id递增 
*/
#include<bits/stdc++.h>
using namespace std;
struct app{
	int id, ge, gi, choices[6], rank;
};
vector<app> a;
bool mycmp(app q, app w){
	if(q.ge + q.gi == w.ge + w.gi) return q.ge > w.ge;
	else return q.ge + q.gi > w.ge + w.gi;
}
struct sch{
	int quota, last;
	vector<int> gra; 
};
vector<sch> s;
int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		sch t;
		scanf("%d", &t.quota);	
		t.last = -1;
		s.push_back(t);
	}
	for(int i = 0; i < n; i++){
		app t; t.id=i;
		scanf("%d%d", &t.ge, &t.gi);
		for(int j = 0; j < k; j++) scanf("%d", &t.choices[j]);
		a.push_back(t);
	}
	sort(a.begin(), a.end(), mycmp);
	// 排名 
	for(int i = 0; i < n; i++){
		if(i != 0 && a[i-1].ge + a[i-1].gi == a[i].ge + a[i].gi && a[i-1].ge == a[i].ge){
			a[i].rank = a[i-1].rank;
		}else a[i].rank = i+1;
	}
	// 选学校 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int cho = a[i].choices[j];
			if(s[cho].quota){
				s[cho].gra.push_back(a[i].id);
				s[cho].quota--;
				s[cho].last = a[i].rank;
				break;
			} else if(s[cho].last >= 0 && a[i].rank == s[cho].last){
				s[cho].gra.push_back(a[i].id);
				s[cho].last = a[i].rank;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++){
		sort(s[i].gra.begin(), s[i].gra.end(), less<int>());
		for(int j = 0; j < s[i].gra.size(); j++){
			if(j != 0) printf(" ");
			printf("%d", s[i].gra[j]);
		}
		printf("\n");
	}
	return 0;
}
