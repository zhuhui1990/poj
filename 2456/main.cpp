#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,m;

const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int x[maxn];

bool C(int d){
	int last = 0;
	for(int i=1;i<m;++i){
		int crt = last + 1;
		while(crt < n && x[crt]-x[last] < d){
			++crt;
		}
		if(crt == n){
			return false;
		}
		last = crt;
	}
	return true;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	int lb = 0,ub = inf;
	while(ub - lb > 1){
		int mid = (lb+ub)/2;
		if(C(mid)){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	printf("%d\n",lb);
	return 0;
}