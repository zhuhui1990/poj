#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1024;

int test[maxn];
int secret[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m;
	int nkase;
	int k,intensity;
	scanf("%d",&nkase);
	for(int kase=0; kase<nkase; ++kase){
		scanf("%d",&n);
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d %d",&k,&intensity);
			test[intensity] = k;
		}		
		scanf("%d",&m);
		memset(secret,-1,sizeof(secret));
		for(int i=0;i<m;++i){
			scanf("%d %d",&k,&intensity);
			secret[k] = intensity;
		}
		printf("Case %d\n",kase+1);
		printf("\n");
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				k = test[i*n+j];
				while(secret[k] == -1){
					k = (k-1)/4;
				}
				printf("%4d",secret[k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}