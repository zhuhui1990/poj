//挑战程序设计竞赛第二版P69
//dp[i+1][j] = 从前i种蚂蚁中取出j个的组合总数
//优化的递推关系式：
// dp[i+1][j] = dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]];
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxt = 1005;
const int maxa = 10005;
const int mod = 1000000;

int dp[maxt][maxa];
int fam[maxt];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,a,s,b;
	cin>>n>>a>>s>>b;
	memset(fam,0,sizeof(fam));
	for(int i=0;i<a;++i){
		int index;
		cin>>index;
		++fam[index];
	}
	for(int i=0;i<=n+1;++i){
		dp[i][0] = 1;
		//cout<<"i="<<i<<" fam[i]="<<fam[i]<<endl;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=b;++j){
			if(j-1-fam[i] >= 0){
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-fam[i]]+mod)%mod;
			}else{
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % mod;
			}
			//cout<<"i="<<i<<" j="<<j<<" dp[i+1][j]="<<dp[i+1][j]<<endl;
		}
	}
	
	int res = 0;
	for(int i=s;i<=b;++i){
		//cout<<"i="<<i<<" dp[n][i]="<<dp[n][i]<<endl;
		res = (res + dp[n+1][i]) % mod;
	}
	cout<<res<<endl;
	
	return 0;
}