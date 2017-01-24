#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 10005;
const int maxc = 10005;
const double M_PI = 3.14159265358979323846; //需要高精度的pi

const int st_size = (1<<15)-1;

int n,c;
int ll[maxn];
int s[maxc],a[maxc];

double vx[st_size],vy[st_size];
double ang[st_size];

double prv[maxn];

void init(int k,int l,int r){
	ang[k] = vx[k] = 0.0;
	if(r-l == 1){
		vy[k] = ll[l];
	}else{
		int chl = k*2+1,chr=k*2+2;
		init(chl,l,(l+r)/2);
		init(chr,(l+r)/2,r);
		vy[k] = vy[chl]+vy[chr];
	}
}

void change(int s,double a,int v,int l,int r){
	if(s<=l){
		return;
	}else if(s<r){
		int chl = v*2+1,chr = v*2+2;
		int m =(l+r)/2;
		change(s,a,chl,l,m);
		change(s,a,chr,m,r);
		if(s<=m){
			ang[v] += a;
		}
		double s = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v] = vy[chl]+(s*vx[chr]+c*vy[chr]);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase = 0; 
	while(cin>>n>>c){
		if(kase != 0){
			printf("\n");
		}
		++kase;
		for(int i=0;i<n;++i){
			cin>>ll[i];
		}
		for(int i=0;i<c;++i){
			cin>>s[i]>>a[i];
		}
		init(0,0,n);
		for(int i=1;i<n;++i){
			prv[i] = M_PI;
		}
		for(int i=0;i<c;++i){
			int ss=s[i];
			double aa=a[i]/180.*M_PI;
			change(ss,aa-prv[ss],0,0,n);
			prv[ss] = aa;
			printf("%.2f %.2f\n",vx[0],vy[0]);
		}
		
	}
	return 0;
}