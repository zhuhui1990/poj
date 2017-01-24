//CatalanÊý
#include <iostream>
#include <cstdio>

using namespace std;

int h[20],s[20];

void initCatalan(){
	h[0] = 1;
	h[1] = 1;
	s[0] = 0;
	s[1] = 1;
	for(int i=2;i<=19;++i){
		int catalan = 0;
		int k=i;
		--k;
		for(int j=0;j<i;++j,--k){
			catalan += h[j]*h[k];
		}
		h[i] = catalan;
		s[i] = s[i-1]+catalan;
	}
}

void outTree(int x,int n){
	if(n==0){
		return;
	}
	if(n==1){
		printf("X");
		return;
	}
	int left;
	int i;
	int j=n;
	--j;
	for(i=0;i<n;++i,--j){
		left = h[i]*h[j];
		if(x>left){
			x -= left;
		}else{
			break;
		}
	}
	--x;
	if(i!=0){
		printf("(");
		outTree((x/h[j])+1,i);
		printf(")");
	}
	printf("X");
	if(j!=0){
		printf("(");
		outTree((x%h[j])+1,j);
		printf(")");
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif 
	initCatalan();
	int n;
	while(scanf("%d",&n) && n){
		int i;
		for(i=1;i<=19;++i){
			if(s[i] >= n){
				break;
			}
		}
		outTree(n-s[i-1],i);
		printf("\n");
	}
	return 0;
}