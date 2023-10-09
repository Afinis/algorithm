#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, c;
struct node{
	int id;
	string name;
	int grade;
}stu[N+5];

bool mycmp(node a, node b){
	if(c==1) return a.id < b.id;
	else if(c==2)
		if(a.name == b.name) return a.id < b.id;
		else return a.name < b.name;
	else if(c==3)
		if(a.grade == b.grade) return a.id < b.id;
		else return a.grade < b.grade;
}

int main(){
	cin>>n>>c;
	for(int i = 0; i < n; i++){
		string na; 
		int id, g;
		cin>>id>>na>>g;
		stu[i] = {id, na, g};
	}
	sort(stu, stu + n, mycmp);
	for(int i = 0; i < n; i++)
		cout<<setw(6)<<setfill('0')<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].grade<<endl;
	return 0;
}
