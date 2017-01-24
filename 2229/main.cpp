//DP
//dp[i]
//如果i是奇数，则所有组合都对应于i-1的组合加上单个1
//如果i是偶数，则所有组合都对应于(i-1的组合加上单个1)和(i/2的组合乘以2)
#include <iostream>

using namespace std;

const int maxn = 1000005;
const int m = 1000000000;
int dp[maxn];

int main(){
	int n;
	cin>>n;
	dp[1] = 1;
	for(int i = 2;i <= n; ++i){
		if(i % 2 != 0){
			dp[i] = dp[i-1];
		}else{
			dp[i] = dp[i-1] + dp[i/2];
		}
		dp[i] %= m;
	}
	cout<<dp[n]<<endl;
	return 0;
}