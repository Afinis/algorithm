#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 55, MAXM = 505, MAXW = 5, MAXK = 200;
const int LOGT = 29, MT_SIZE = MAXN*5;;
const ll LL_INF = 1e18;

int n, m, t, k, c[MAXN];
int id[MAXN][MAXW+5], cnt_id;

struct Matrix{
	ll e[MT_SIZE+5][MT_SIZE+5];
	int size;
	void identity() {
		for(int i=1; i <= size;++i) {
			for(int j=1; j <= size;++j){
				e[i][j] = (i==j ? 0 : -LL_INF);
			}
		}
	}
	Matrix(){
		for(int i=1;i<=MT_SIZE;++i)
			for(int j=1;j<=MT_SIZE;++j)
				e[i][j] = -LL_INF;
		size=0;
	}
};

Matrix operator * (const Matrix& A, const Matrix& B){
	Matrix C;
	C.size = A.size;
	for(int i=1;i<=A.size;++i){
		for(int j=1;j<=A.size;++j){
			for(int k=1;k<=A.size;++k){
				if(A.e[i][k] == -LL_INF || B.e[k][j] == -LL_INF)
					continue;
				C.e[i][j] = max(C.e[i][j], A.e[i][k]+B.e[k][j]);
			}
		}
	}
	return C;
}

Matrix mat_pow(Matrix X,int i) {
	Matrix Y;
	Y.size = X.size;
	Y.identity();
	while(i){
		if(i&1) Y=Y*X;
		X=X*X;
		i>>=1;
	}
	return Y;
}

struct Event{
	int t,u,w;
	bool operator < (const Event& x) const {
		return t < x.t;
	}
}ev[MAXK+5];

Matrix trans , pow_of_trans[LOGT+1];

void init_pow_of_trans() {
	pow_of_trans[0] = trans;
	for(int i=1; i<=LOGT; ++i) {
		pow_of_trans[i] = pow_of_trans[i-1] * pow_of_trans[i-1];
	}
}

void mul_pow_of_trans(Matrix& A, int mi) {
	for(int bit=0; bit<=LOGT; ++bit) {
		if((mi>>bit) & 1) {
			//œÚ¡ø≥Àæÿ’Û
			Matrix res;
			res.size=A.size;
			for(int j=1; j<=A.size; ++j) {
				for(int k=1; k<=A.size; ++k) {
					if(A.e[1][k] == -LL_INF || pow_of_trans[bit].e[k][j] == -LL_INF)
						continue;
					res.e[1][j] = max(res.e[1][j], A.e[1][k] + pow_of_trans[bit].e[k][j]);
				}
			}
			A = res;
		}
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);	
	trans.size = n*5;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j)
			id[i][j] = ++cnt_id;
		for(int j=1;j<5;++j)
			trans.e[id[i][j]][id[i][j+1]] = 0;
	}
	
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		trans.e[id[u][w]][id[v][1]]=c[v];
	}
	for(int i=1; i<=k; ++i) 
		scanf("%d%d%d", &ev[i].t, &ev[i].u, &ev[i].w);
	sort(ev+1, ev+k+1);	
	
	Matrix A;
	A.size = n*5;
	A.e[1][id[1][1]] = c[1];
	init_pow_of_trans();
	
	int last_time = 0;
	for(int i=1; i<=k; ++i) {
		mul_pow_of_trans(A, ev[i].t - last_time);
		if(A.e[1][id[ev[i].u][1]] != -LL_INF)
			A.e[1][id[ev[i].u][1]] += ev[i].w;
		last_time = ev[i].t;
	}
	if(last_time != t)
		mul_pow_of_trans(A, t - last_time);
	
	if(A.e[1][id[1][1]] == -LL_INF) printf("-1");
	else printf("%lld", A.e[1][id[1][1]]);
	return 0;
}
