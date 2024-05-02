#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;

struct node{
	int win, lose;
}tr[N];
int k, l;
bool flag = false;

bool dfs(int p) {
    if(tr[p].win < tr[p].lose) return false;

    if(p*2+1 <= l){
    	tr[p*2].win = tr[p].win;
	    tr[p*2+1].win = tr[p].lose;
	    if(dfs(p*2) && dfs(p*2+1))
	    	return true;
		
	    tr[p*2].win = tr[p].lose;
	    tr[p*2+1].win = tr[p].win;
	    if(dfs(p*2) && dfs(p*2+1))
	    	return true;
	}else{
		return true;
	}
    return false;
}


int main(){
	cin>>k;
	l = (1<<k) - 1;
	for(int i = 1; i <= k; i++){
		int n = 1<<(k-i);
		int s = 1<<(k-i);
		while(n--){
			cin>>tr[s].lose;
			s++;
		}
	}
	cin>>tr[1].win;
 
	if(!dfs(1)){
		cout<<"No Solution"<<endl;
	}else{
		for(int i = 1<<(k-1); i <= l; i++){
			cout<<tr[i].win<<" "<<tr[i].lose;
			if(i != l) cout<<" ";
		}		
	}
	return 0;
}
