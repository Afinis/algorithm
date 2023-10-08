#include <bits/stdc++.h>
using namespace std;

int rate[25];
struct node{
    int mon, d, h, m;
    int type=0;
};
map<string, vector<node> > bills;
bool mycmp(node a, node b){
    if(a.mon < b.mon) return true;
    else if (a.mon > b.mon) return false;
    if(a.d < b.d) return true;
    else if (a.d > b.d) return false;
    if(a.h < b.h) return true;
    else if (a.h > b.h) return false;
    if(a.m < b.m) return true;
    else if (a.m > b.m) return false;
    return false;
}
int lasting(node a, node b){
    return (b.d - a.d)*24*60 + (b.h-a.h)*60 + (b.m-a.m);
}
double charge(node a, node b){
	int r = 0;
	while(a.d < b.d || a.h < b.h || a.m < b.m){
		a.m++;
		r += rate[a.h];
		if(a.m == 60){
			a.m = 0;
			a.h++;
		}
		if(a.h == 24){
			a.h = 0;
			a.d++;
		}
	} 
    return r/100.0;
}

int main(){
    for(int i = 0; i < 24; i++) scanf("%d", rate+i);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char cna[25], ct[25]; scanf("%s", cna);
        int mm, d, h, m, on; scanf("%d:%d:%d:%d", &mm, &d, &h, &m );
        scanf("%s", ct);
        string na(cna), t(ct);
        t == "on-line" ? on = 1 : on = 0;
        node no; no.mon=mm; no.d=d; no.m=m; no.h=h; no.type=on;
        bills[na].push_back(no);
    }
    for(map<string, vector<node> >::iterator it = bills.begin(); it != bills.end(); it++)
        sort(it->second.begin(), it->second.end(), mycmp);
    for(auto it = bills.begin(); it != bills.end(); it++){
        string name = it->first;
        vector<node> bill = it->second;
        int en = 0;
        for(int i = 0; i < bill.size(); i++)
        	if(en == 0 && bill[i].type == 1) en = 1;
			else if (en == 1 && bill[i].type==0) en = 2;
		if (en < 2) continue;
        printf("%s %02d\n", name.c_str(), bill[0].mon);
        node lo, hi;
        double tota = 0;
        for(int i = 0; i < bill.size(); i++){
            node e = bill[i];
            if(e.type == 1 && i != bill.size()-1 && bill[i+1].type==0){
                lo = e, hi = bill[i+1];
                int last = lasting(lo, hi);
                double fee = charge(lo, hi);
                tota += fee;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                       lo.d, lo.h, lo.m, hi.d, hi.h, hi.m, last, fee);
                i++;
            }
        }
        printf("Total amount: $%.2f\n", tota);
    }
}
