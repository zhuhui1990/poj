//DP
//x是原字符串，y是x逆序
//ans = x.length() - LCS(x,y)
//用滚动数组
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5005;
int dp[2][maxn]; //滚动数组

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	string x,y;
	cin>>x;
	y = x;
	reverse(x.begin(),x.end());
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(x[i-1] == y[j-1]){
				dp[i%2][j] = dp[(i-1)%2][j-1]+1;
			}else{
				dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
			}
			//cout<<"i="<<i<<" j="<<j<<" dp[i%2][j]="<<dp[i%2][j]<<endl;
		}
		
	}
	cout<<n - dp[n%2][n]<<endl;
	return 0;
}
