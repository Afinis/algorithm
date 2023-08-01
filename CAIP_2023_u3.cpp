#include<bits/stdc++.h>
using namespace std;


int a[5], b[5];
int c[5];
int cnt[7];
int zans[500];

int countlv(int* arr) {
    for(int i = 0; i < 5; ++i) c[i] = arr[i];
    sort(c, c + 5);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < 5; ++i) cnt[c[i]]++;
    //five-in-kind: lv8
    for(int i = 1; i <= 6; ++i) if(cnt[i] == 5) return 8;
    //four-in-kind: lv7
    for(int i = 1; i <= 6; ++i) if(cnt[i] == 4) return 7;
    //full house: lv6
    for(int i = 1; i <= 6; ++i)
        for(int j = 1; j <= 6; ++j)
            if(cnt[i] == 3 && cnt[j] == 2) return 6;
    //six high: lv5
    if(c[0] == 2 && c[1] == 3 && c[2] == 4 && c[3] == 5 && c[4] == 6) return 5;
    //five high: lv4
    if(c[0] == 1 && c[1] == 2 && c[2] == 3 && c[3] == 4 && c[4] == 5) return 4;
    //three-in-kind: lv3
    for(int i = 1; i <= 6; ++i) if(cnt[i] == 3) return 3;
    //two pair: lv2
    for(int i = 1; i <= 6; ++i)
        for(int j = 1; j <= 6; ++j)
            if(i != j && cnt[i] == 2 && cnt[j] == 2) return 2;
    //one pair: lv1
    for(int i = 1; i <= 6; ++i) if(cnt[i] == 2) return 1;
    //no: lv0
    return 0;
}

int main(){
	
	int t;
	scanf("%d", &t);
	for(int xx = 0; xx < t; xx++){
		memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(cnt, 0, sizeof(cnt));
        memset(zans, 0, sizeof(zans));
        			
		for(int i = 0; i < 5; ++i) {
			scanf("%d", &a[i]);
		}
		
		int nowlv = countlv(a);
		memset(zans, 0, sizeof(zans));
		for(b[0] = 1; b[0] <= 6; ++b[0])
	        for(b[1] = 1; b[1] <= 6; ++b[1])
	            for(b[2] = 1; b[2] <= 6; ++b[2])
	                for(b[3] = 1; b[3] <= 6; ++b[3])
	                    for(b[4] = 1; b[4] <= 6; ++b[4]) {
	                    	int sta = 0;
	                    	for(int i = 0; i < 5; ++i) {
	                    		if(a[i] != b[i]) sta += (1<<i);
							}
	                    	int newlv = countlv(b);
	                    	if(nowlv < newlv) zans[sta]++;
						}
						
		int besttot = -1, bestcnt = 9999, beststa;
		for(int i = 0; i < (1 << 5); ++i) {
			int cnt = __builtin_popcount(i);
			int tot = 0;
			for(int j = 0; j < (1 << 5); ++j){
				if((i | j) == i) tot += zans[j];
			}
			while(cnt != 5) {
                tot *= 6;
                cnt++;
            }
            
            if(tot > besttot) {
                besttot = tot;
                bestcnt = __builtin_popcount(i);
                beststa = i;
            } else if(tot == besttot && __builtin_popcount(i) < bestcnt) {
                bestcnt = __builtin_popcount(i);
                beststa = i;
            }
            
		}
		
		int gg = __gcd(besttot, 7776); // 6^5
        printf("%d %d %d\n", bestcnt, besttot / gg, 7776 / gg);
	}
	
	
	return 0;
}
