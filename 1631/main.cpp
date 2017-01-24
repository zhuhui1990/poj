#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 40005;
int a[maxn];
int dp[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
			//cout<<"i="<<i<<" a[i]="<<a[i]<<endl;
		}
		fill_n(dp,n,maxn);
		for(int i=0;i<n;++i){
			*lower_bound(dp,dp+n,a[i]) = a[i];
		}
		cout<<lower_bound(dp,dp+n,maxn)-dp<<endl;
	}
	return 0;
}