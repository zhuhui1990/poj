#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 105;
const double g = 10.0;

int n,h,r,t;
double y[maxn];

double calc(int tt){
	if(tt<0){
		return h;
	}
	double t = sqrt(2.*h/g);
	int k = int(tt/t);
	if(k%2==0){
		double d = tt-k*t;
		return h-g*d*d/2;
	}else{
		double d = k*t+t-tt;
		return h-g*d*d/2;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	while(kase--){
		cin>>n>>h>>r>>t;
		for(int i=0;i<n;++i){
			y[i] = calc(t-i);
		}
		sort(y,y+n);
		for(int i=0;i<n;++i){
			printf("%.2f%c",y[i]+2*r*i/100.,i+1==n?'\n':' ');
		}
	}
	return 0;
}