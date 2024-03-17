#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
char s[M];
struct node{
	int l, r;
	int laz[30];
}t[M*4];

int mp(char c){
	return c-'a'+1;
}

char toC(int i){
	return i-1+'a';
}

void build(int l, int r, int p){
	t[p].l = l, t[p].r = r;
    for (int i = 1; i < 27; ++i) {
        t[p].laz[i] = i;
    }
	if(l==r){
		return;
	}
	int mi = (l+r)/2;
	build(l, mi, p*2);
	build(mi+1, r, p*2+1);
}

void pushDown(int p){
	for(int i = 1; i <= 26; i++){
		t[p*2].laz[i] = t[p].laz[ t[p*2].laz[i] ];
		t[p*2+1].laz[i] = t[p].laz[ t[p*2+1].laz[i] ];
	}
    for(int i = 1; i <= 26; i++){
        t[p].laz[i] = i;
    }
}

void update(int l, int r, char u, char v , int p){
	if(l<=t[p].l && t[p].r<=r){
        for (int i = 1; i < 27; ++i) {
            if (t[p].laz[i] == mp(u)){
                t[p].laz[i] = mp(v);
            }
        }
        return;
	}
	int mi = (t[p].l+t[p].r)/2;
	pushDown(p);
	if(l<=mi) update(l, r, u, v, p*2);
	if(mi<r) update(l, r, u, v, p*2+1);
}

void outp(int l, int r, int p){
    if (l == r){
        printf("%c", toC(t[p].laz[mp(s[l])]) );
        return;
    }
    pushDown(p);
    int mi = (l+r)/2;
    outp(l, mi, p*2);
    outp(mi+1, r, p*2+1);
}

int main(){
	scanf("%s", s);
	int ls = strlen(s), m;
	build(0, ls-1, 1);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r;
        char x, y;
		scanf("%d%d %c %c", &l, &r, &x, &y);
		l--; r--;
		update(l, r, x, y, 1);
	}
    outp(0, ls-1, 1);
	return 0;
}
