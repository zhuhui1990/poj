#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 10005;
const double inf = 1e10;
double l[maxn];
int n,k;

bool C(double x){
	int num = 0;
	for(int i=0;i<n;++i){
		num += int (l[i]/x);
	}
	return num >= k;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>l[i];
	}
	double lb = 0,ub = inf;
	for(int i=0;i<50;++i){
		double mid = (lb+ub)/2;
		if(C(mid)){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	printf("%.2f\n",floor(ub*100)/100);
	return 0;
}
