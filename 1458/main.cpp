#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;
int dp[maxn][maxn];
// dp[i][j] = s1前i个字符和s2前j个字符的最长子序列长度
// dp[i][j] = dp[i-1][j-1] + 1 ; if s1[i] == s2[j]
// dp[i][j] = max(dp[i-1][j],dp[i][j-1]); else
// dp[0][j] = 0,dp[i][0] = 0;

int processDP(int i,int j,const string& s1,const string& s2){
	//cout<<"i="<<i<<" j="<<j<<endl;
	if(dp[i][j] >= 0){
		return dp[i][j];
	}
	if(i == 0 || j == 0){
		dp[i][j] = 0;
		return 0;
	}
	if(s1[i-1] == s2[j-1]){
		return dp[i][j] = processDP(i-1,j-1,s1,s2)+1;
	}else{
		return dp[i][j] = max(processDP(i-1,j,s1,s2),processDP(i,j-1,s1,s2));
	}
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s1,s2;
	while(cin>>s1>>s2){
		//记忆化搜索
		memset(dp,-1,sizeof(dp));
		cout<<processDP(s1.length(),s2.length(),s1,s2)<<endl;
	}
	return 0;
}