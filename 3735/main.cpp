//矩阵乘法+矩阵快速幂

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;

struct mat{
	long long v[maxn][maxn];
	mat(){
		memset(v,0,sizeof(v));
	}
	
};

mat e,ans;
int n,m,k;

mat matrix_mul(const mat& p1,const mat& p2){
	mat t;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(p1.v[i][j] != 0){ //优化
				for(int k=0;k<=n;++k){
					t.v[i][k] += p1.v[i][j]*p2.v[j][k];
				}
			}
		}
	}
	return t;
}

mat matrix_mi(mat& p,int k){ //矩阵快速幂
	mat t;
	for(int i=0;i<=n;++i){
		t.v[i][i] = 1;
	}
	while(k){
		if(k & 1){
			t = matrix_mul(t,p);
		}
		k >>= 1;
		p = matrix_mul(p,p);
	}
	return t;
}

void init(){
	int x,y,t;
	char w[2];
	memset(e.v,0,sizeof(e.v));
	for(int i=0;i<=n;++i){
		e.v[i][i] = 1;
	}
	while(k--){
		scanf("%s",w);
		if(w[0] == 'g'){
			scanf("%d",&x);
			--x;
			++e.v[n][x];
		}else if(w[0] == 's'){
			scanf("%d %d",&x,&y);
			--x;
			--y;
			if(x!=y){
				for(int i=0;i<=n;++i){
					t = e.v[i][x];
					e.v[i][x] = e.v[i][y];
					e.v[i][y] = t;
				}
			}
		}else{
			scanf("%d",&x);
			--x;
			for(int i=0;i<=n;++i){
				e.v[i][x] = 0;
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	while(scanf("%d %d %d",&n,&m,&k)){
		if( n ==0 && m == 0 && k == 0){
			break;
		}
		init();
		ans = matrix_mi(e,m);
		for(int i=0;i<n;++i){
			printf("%lld ",ans.v[n][i]);
		}
		printf("\n");
	}
	return 0;
}