#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 1005;
const int max_ml = 10005;
const int max_md = 10005;
const int inf = 0xffffff;

int al[max_ml],bl[max_ml],dl[max_ml];
int ad[max_md],bd[max_md],dd[max_md];

int d[max_n];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,ml,md;
	scanf("%d %d %d",&n,&ml,&md);
	for(int i=0;i<ml;++i){
		scanf("%d %d %d",&al[i],&bl[i],&dl[i]);
	}
	for(int i=0;i<md;++i){
		scanf("%d %d %d",&ad[i],&bd[i],&dd[i]);
	}
	fill(d,d+n,inf);
	d[0] = 0;
	//Bellman-Ford
	for(int k=0;k<n;++k){
		for(int i=0;i<n-1;++i){
			if(d[i+1]<inf){
				d[i] = min(d[i],d[i+1]);
			}
		}
		for(int i=0;i<ml;++i){
			if(d[al[i]-1]<inf){
				d[bl[i]-1] = min(d[bl[i]-1],d[al[i]-1]+dl[i]);
			}
		}
		for(int i=0;i<md;++i){
			if(d[bd[i]-1]<inf){
				d[ad[i]-1] = min(d[ad[i]-1],d[bd[i]-1]-dd[i]);
			}
		}
	}
	int res = d[n-1];
	if(d[0] < 0){ //¸ºÈ¦£¬ÎÞ½â
		res = -1;
	}else if(res == inf){
		res = -2;
	}
	printf("%d\n",res);
	return 0;
}