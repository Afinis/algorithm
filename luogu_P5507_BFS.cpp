#include<bits/stdc++.h>
using namespace std;
const int MXN=(1<<24)+10;
int mp[15][5], r, fa[100], fb[100];
unordered_map<int, int> visf, visb, pref, preb, idf, idb;
//int visf[MXN], visb[MXN], pref[MXN], preb[MXN], idf[MXN], idb[MXN];
int sta(int s, int i){
	int t = ((s >> ((i-1)*2)) & 3) + 1;
	return t;
}
int forward(int f, int i, int ne){
	int a = sta(f, i), b = sta(f, ne);
	f -= (f & (3 << ((i-1)*2))) + (f & (3 << ((ne-1)*2)));
	f += ((a & 3)<<((i-1)*2)) + ((b & 3)<<((ne-1)*2));
	return f;
}
int  backward(int f, int i, int ne){
	int a = sta(f, i), b = sta(f, ne);
	f -= (f & (3 << ((i-1)*2))) + (f & (3 << ((ne-1)*2)));
	f += (((a - 2) & 3)<<((i-1)*2)) + (((b - 2) & 3)<<((ne-1)*2));
	return f;
}
int main(){
	int be = 0, ed = 0;
	for(int i = 0; i < 12; i++){
		int t;
		cin>>t;
		be += (t-1)<<(i<<1);
		for(int j = 1; j < 5; j++) cin>>mp[i+1][j];
	}
	queue<int> fq, bq;
	fq.push(be); bq.push(ed);
	visf[be] = 1; visb[ed] = 1;
	while(!fq.empty() && !bq.empty()){
		int f = fq.front(); fq.pop();
		int b = bq.front(); bq.pop();
		if(visf[b] && visb[b]){
			r = b;
			break;
		}else if(visb[f] && visf[f]){
			r = f;
			break;
		}
		for(int i = 1; i <= 12; i++){
			int ne = mp[i][sta(f, i)];
			int newf = forward(f, i, ne);
			if(!visf[newf]){
				fq.push(newf);
				visf[newf] = 1;
				pref[newf] = f;
				idf[newf] = i;
			}
			int ts = sta(b, i)-1 == 0 ? 4 : sta(b, i)-1;
			ne = mp[i][ts]; 
			int newb = backward(b, i, ne);
			if(!visb[newb]){
				bq.push(newb);
				visb[newb] = 1;
				preb[newb] = b;
				idb[newb] = i;
			}
		}
	}
	int cf=0, cb=0;
	int t = r;
	while(t != be){
		fa[cf++] = idf[t];
		t = pref[t];
	}
	t = r;
	while(t != ed){
		fb[cb++] = idb[t];
		t = preb[t];
	}
	cout<<cf+cb<<endl;
	for(int i = cf-1; i >= 0; i--){
		if(i != cf-1) cout<<" ";
		cout<<fa[i];
	}
	for(int i = 0; i < cb; i++){
		if(i!=0 || (i==0&&cf!=0)) cout<<" ";
		cout<<fb[i];
	}
	return 0;
}
