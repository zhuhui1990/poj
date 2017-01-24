//dp[i][j] := 前i + 1个数变成单调且最后一个数是B[j]，此时的最小成本
//dp[i][j]  = min(dp[i – 1][k]) + |A[i] – B[j]|       (k = 0…j)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	memcpy(b,a,n*sizeof(int));
	sort(b,b+n);
	for(int j=0;j<n;++j){
		dp[0][j] = abs(a[0]-b[j]);
	}
	for(int i=1;i<n;++i){
		int pre_min_cost = dp[i-1][0];
		for(int j=0;j<n;++j){
			pre_min_cost = min(pre_min_cost,dp[i-1][j]);
			dp[i][j] = pre_min_cost + abs(a[i]-b[j]);
		}
	}
	cout<< *min_element(dp[n-1],dp[n-1]+n)<<endl;
	return 0;
}