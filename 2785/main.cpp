#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 4005;
int a[maxn],b[maxn],c[maxn],d[maxn];
int cd[maxn*maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cd[i*n+j] = c[i]+d[j];
		}
	}
	sort(cd,cd+n*n);
	long long res = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int p = -a[i]-b[j];
			res += upper_bound(cd,cd+n*n,p)-lower_bound(cd,cd+n*n,p);
		}
	}
	cout<<res<<endl;
	return 0;
}