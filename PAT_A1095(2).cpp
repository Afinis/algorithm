#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
struct Car{
	char id[8];
	int time;
	char status[4];
}all[maxn], valid[maxn];
int num = 0; //有效记录的条数 
map<string, int> parkTime;
int timeToInt(int h, int m, int s){
	return h*3600 + m*60 + s;
}
bool cmpByTime(Car a, Car b){
	return a.time < b.time;
}
bool cmpByIdAndTime(Car a, Car b){
	if(strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
	else return a.time < b.time;
}
int main(){
	int n, k, h,m,s;
	scanf("%d%d", &n, &k);	
	for(int i = 0;i < n; i++){
		scanf("%s %d:%d:%d %s", all[i].id, &h, &m, &s, all[i].status);
		all[i].time = timeToInt(h,m,s);
	}
	sort(all, all+n, cmpByIdAndTime);
	int maxTime = -1;
	for(int i = 0; i < n-1; i++){
		if(!strcmp(all[i].id, all[i+1].id ) && 
		!strcmp(all[i].status, "in") && !strcmp(all[i+1].status, "out") ){
			valid[num++] = all[i];
			valid[num++] = all[i+1];
			int inTime = all[i+1].time - all[i].time;
			parkTime[all[i].id] += inTime;
			maxTime = max(parkTime[all[i].id], maxTime);
		}
	}
	sort(valid, valid+num, cmpByTime);
	int now = 0, numCar = 0;
	for(int i = 0;i < k; i++){
		scanf("%d:%d:%d", &h, &m, &s);	
		int time = timeToInt(h,m,s);
		while(now < num && valid[now].time <= time){
			if(!strcmp(valid[now].status, "in")) numCar++;
			else numCar--;
			now++;
		}
		printf("%d\n", numCar); 
	}
	for(auto it = parkTime.begin(); it != parkTime.end(); it++){
		if(it->second == maxTime){
			printf("%s ", it->first.c_str()); 
		}
	}
	printf("%02d:%02d:%02d", maxTime/3600, maxTime%3600/60, maxTime%60 );
	return 0;
}
