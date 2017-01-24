#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 1005;

double x;
double y;

struct Interval{
	double start,end;
};

bool comp(const Interval& lhs, const Interval& rhs){
	return lhs.start < rhs.start;
}

Interval inter[maxn];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	double r;
	int kase=0;
	while(scanf("%d %lf",&n,&r) && (n !=0 || r !=0.)){
		bool flag=false;
		++kase;
		for(int i=0;i<n;++i){
			scanf("%lf %lf",&x,&y);
			if(y > r){
				flag = true;
				continue;
			}
			inter[i].start = x - sqrt(r*r-y*y);
			inter[i].end   = x + sqrt(r*r-y*y);
		}
		if(flag){
			printf("Case %d: -1\n",kase);
			continue;
		}
		sort(inter,inter+n,comp);
	
		int ans = 0;
		double end = -1e10;
		for(int i=0;i<n;++i){
			if(end < inter[i].start){
				++ans;
				end = inter[i].end;
			}else if(end > inter[i].end){
				end = inter[i].end;
			}
		}
		
		
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}