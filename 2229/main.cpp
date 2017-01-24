//DP
//dp[i]
//���i����������������϶���Ӧ��i-1����ϼ��ϵ���1
//���i��ż������������϶���Ӧ��(i-1����ϼ��ϵ���1)��(i/2����ϳ���2)
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