#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N], r[N], olda[N];

bool isSame(int c[]){
	for(int i = 0; i < n; i++)
		if(c[i]!=b[i]) return false;
	return true;
}

void merge(int lo, int mi, int hi, int a[]){ 
	int b[mi-lo], lb = mi - lo, lc = hi-mi;
	for(int i = 0; i < lb; i++) b[i]=a[lo+i];
	int i = 0, j = 0, k = 0;
	while(j < lb && k < lc)
		a[lo+(i++)] = b[j] < a[mi+k] ? b[j++] : a[mi+(k++)];
	while(j<lb) a[lo+(i++)] = b[j++];
}

// 递归版本的归并排序在这里不能用 
void mergeSort(int lo, int hi, int e[]){ 
	int en = 0;
	if(isSame(e)) en = 1;
	if(hi-1 <= lo) return;
	int mi = (lo+hi)/2;
	mergeSort(lo, mi, e);
	mergeSort(mi, hi, e);
	merge(lo, mi, hi, e);
	if(en) return;
}

void mergeSortIt(int lo, int hi, int e[]){
    int l = hi - lo, en=0;
    for (int step = 2; step/2 < l; step*=2) {
    	if(isSame(e)) en = 1;
        for (int i = 0; i < l; i+=step) {
            int mi = lo + i + step/2;
            if(mi < hi) merge(lo+i, mi, min(lo+i+step, hi), e);
        }
        if(en) return;
    }
}

bool insertSort(int lo, int hi, int a[]){
	int l = hi - lo, en = 0;
	for(int i = 0; i < l; i++){
		if(isSame(a)) en = 1;
		int p = upper_bound(a+lo, a+lo+i, a[i]) - a;
		int t = a[i], q = i;
		while(q > p){
			a[q] = a[q-1];
			q--;
		}
		a[p]=t;
		if(en)
			if(!isSame(a))  // 测试点2 
				return true;
	}
	return false;
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		olda[i] = a[i];
	}
	for(int i = 0; i < n; i++) cin>>b[i];
	if(insertSort(0, n, a)){
		cout<<"Insertion Sort"<<endl;
		for(int i = 0; i < n; i++){
			if(i!=0) cout<<" ";
			cout<<a[i];
		}
	}else{
		mergeSortIt(0, n, olda);
		cout<<"Merge Sort"<<endl;
		for(int i = 0; i < n; i++){
			if(i!=0) cout<<" ";
			cout<<olda[i];
		}		
	}
	return 0;
}
