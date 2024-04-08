#include<bits/stdc++.h>
using namespace std;
int n = 30, m = 50;
string g[200];
unordered_map<string, int> mp;
int c = 0;
void row(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		for(int k = j+1; k < m; k++)
		for(int l = k+1; l < m; l++)
			if(g[i][j]<g[i][k] && g[i][k]<g[i][l]){
				string t = string(1, g[i][j]);
				t += g[i][k];
				t += g[i][l];
				mp[t]++;
                c++;
			}
	}
}

void col(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
		for(int k = j+1; k < n; k++)
		for(int l = k+1; l < n; l++)
			if(g[j][i]<g[k][i] && g[k][i]<g[l][i]){
				string t = string(1, g[j][i]);
				t += g[k][i];
				t += g[l][i];
				mp[t]++;
                c++;
			}
	}
}

void K1(){
	// 左下右上
	for(int i = 0; i < n; i++){
        // g[i][0]
		for(int j = 0; i-j>=0&&j<m; j++)
		for(int k = j+1; i-k>=0&&k<m; k++)
		for(int l = k+1; i-l>=0&&l<m; l++){
			if(g[i-j][j]<g[i-k][k] && g[i-k][k]<g[i-l][l]){
				string t = string(1, g[i-j][j]);
				t += g[i-k][k];
				t += g[i-l][l];
				mp[t]++;
                c++;
			}
			if(g[i-j][j]>g[i-k][k] && g[i-k][k]>g[i-l][l]){
				string t = string(1, g[i-l][l]);
				t += g[i-k][k];
				t += g[i-j][j];
				mp[t]++;
                c++;
			}
		}
	}

	for(int i = 1; i < m; i++){
        // g[n-1][i]
		for(int j = 0; n-1-j>=0&&i+j<m; j++)
		for(int k = j+1; n-1-k>=0&&i+k<m; k++)
		for(int l = k+1; n-1-l>=0&&i+l<m; l++){
            if(g[n-1-j][i+j]<g[n-1-k][i+k]&&g[n-1-k][i+k]<g[n-1-l][i+l]){
                string t = string(1, g[n-1-j][i+j]);
                t += g[n-1-k][i+k];
                t += g[n-1-l][i+l];
                mp[t]++;
                c++;
            }
            if(g[n-1-j][i+j]>g[n-1-k][i+k]&&g[n-1-k][i+k]>g[n-1-l][i+l]){
                string t = string(1, g[n-1-l][i+l]);
                t += g[n-1-k][i+k];
                t += g[n-1-j][i+j];
                mp[t]++;
                c++;
            }
        }

	}
}
void K2(){
	// 左上右下
	for(int i = 0; i < m; i++)
		for(int j = 0; j<n&&i+j<m; j++)
		for(int k = j+1; k<n&&i+k<m; k++)
		for(int l = k+1; l<n&&i+l<m; l++)
			if(g[j][i+j]<g[k][i+k]&&g[k][i+k]<g[l][i+l]){
				string t = string(1, g[j][i+j]);
				t += g[k][i+k];
				t += g[l][i+l];
				mp[t]++;
                c++;
			}
	for(int i = 1; i < n; i++)
		for(int j = 0; i+j<n&&j<m; j++)
		for(int k = j+1; i+k<n&&k<m; k++)
		for(int l = k+1; i+l<n&&l<m; l++)
			if(g[i+j][j]<g[i+k][k]&&g[i+k][k]<g[i+l][l]){
				string t = string(1, g[i+j][j]);
				t += g[i+k][k];
				t += g[i+l][l];
				mp[t]++;
                c++;
			}

}

int main(){
	for(int i = 0; i < n; i++) cin>>g[i];
	row();
	cout<<mp.size()<<", "<<c<<endl;
	col();
	cout<<mp.size()<<", "<<c<<endl;
	K1();
	cout<<mp.size()<<", "<<c<<endl;
	K2();
	cout<<mp.size()<<", "<<c<<endl;
    // 180414
	return 0;
}
