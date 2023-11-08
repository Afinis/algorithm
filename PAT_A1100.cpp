#include<bits/stdc++.h>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", 
"jly", "aug", "sep", "oct", "nov", "dec"};

string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", 
"hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170]; //数字转火星文 
map<string, int> strToNum; //火星文转数字 
void init(){
	for(int i = 0; i < 13; i++){
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i;
		numToStr[i*13] = tenDigit[i];
		strToNum[tenDigit[i]] = i*13;
	} 
	for(int i = 1; i < 13; i++){
		for(int j = 1; j < 13; j++){
			string s = tenDigit[i] + " " + unitDigit[j];
			numToStr[i*13 + j] = s;
			strToNum[s] = i*13 + j;
		}
	}
}

int main(){
	init();
	int n; scanf("%d", &n);
	getchar(); //读取换行符 
	while(n--){
		string s;
		getline(cin, s);
		if('0' <= s[0] && s[0] <= '9'){
			int num = atoi(s.c_str());
			cout<<numToStr[num]<<endl;
		}else{
			cout<<strToNum[s]<<endl;
		}
	}
	return 0;
}
