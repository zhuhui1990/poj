//变形01背包
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxm = 210000;
const int shift = 10000;
const int inf = 0xffffff;

int dp[maxm]; //dp[i]: ts=i时，最大的tf值
int a[maxn],b[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	while(cin>>n){
		for(int i=0;i<n;++i){
			cin>>a[i]>>b[i];
		}
		fill_n(dp,maxm,-inf);
		dp[shift] = 0;
		for(int i=0;i<n;++i){
			if(a[i] > 0){
				for(int j=maxm-1;j>=a[i];--j){
					dp[j] = max(dp[j-a[i]]+b[i],dp[j]);
				}
			}else{
				for(int j=0;j<maxm+a[i];++j){
					dp[j] = max(dp[j-a[i]]+b[i],dp[j]);
				}
			}
		}
		int ans=0;
		for(int i=shift;i<maxm;++i){
			if(dp[i] > 0 && (i-shift+dp[i] > ans)){
				ans = i-shift+dp[i];	
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};