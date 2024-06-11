#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n = 0;

bool cmp1(char x) {
	return '0' <= x && x <= '9';
}
bool cmp2(char x) {
	return 'a' <= x && x <= 'z';
}

bool y = false;

void gaus(vector<vector<double> > &a, int k, int row, int col) {
/*	if(row < col) {
		y = true;
		return;
	}

*/
	if(k >= row || k >= col) {
	/*	for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		int t = 0;
		for(int i = 0; i < row; i++) {
			int en = 0;
			for(int j = 0; j < col; j++) {
				if(a[i][j] > 0) {
					en++;
					break;
				}
			}
			if(en) t++;
		}
		y = t < col; 
		return;
	}
	int en = 1;
	for(int i = k; i < row; i++) {
		if(a[i][k]) {
			en = 0;
			break;
		}
	}
	if(en) {
		gaus(a, k+1, row, col);
		return;
	}
	if(a[k][k] == 0) {
		int t = k;
		for(int i = k+1; i < row; i++) {
			if(a[i][k]) {
				t = i;
				break;
			}
		}
		swap(a[k], a[t]);
	}

	for(int i = k+1; i < row; i++) {
		if(a[i][k] == 0) continue;
		double t = -a[i][k]/a[k][k];
		for(int j = 0; j < col; j++) {
			a[i][j] = t * a[k][j] + a[i][j];
			int p1 = a[i][j], p2 = a[k][j];
			int ccc = 0;
		}
	}
	gaus(a, k+1, row, col);
}



void solve() {
	vector<vector<double> > a(N, vector<double>(N, 0));
	int row=0;
	unordered_map<string, int> mp;
	
	int col;
	cin>>col;
	string s;
	for(int j = 0; j < col; j++) {
		cin>>s;
		int pos = 0;
		while(s.size()) {
			auto it = find_if(s.begin(), s.end(), cmp1);
			string e = s.substr(0, it-s.begin());
			if(!mp.count(e)) {
				mp[e] = row;
				row++;
			}
			s = s.substr(it-s.begin(), s.end()-it);
			it = find_if(s.begin(), s.end(), cmp2);
			string snum = s.substr(0, it-s.begin());
			int num = stoi(snum.c_str());
			a[mp[e]][j] = num;
			s = s.substr(it-s.begin(), s.end()-it);
		}

	}
/*
	cout<<"ÐÐ£º"<<row<<" ÁÐ£º"<<col<<endl;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	gaus(a, 0, row, col);
}


int main() {
	cin>>n;
	for(int i = 0; i < n; i++) {
		y = false;
		solve();
		if(y) {
			cout<<"Y"<<endl;
		} else {
			cout<<"N"<<endl;
		}

	}

	return 0;
}
