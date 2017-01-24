// dp[i][j] = ��iԪ���򵥼۲�����jԪ�Ķ������ж����ַ���
// dp[i][j] = dp[i][j-1] + dp[i-j][j]
// ��һ���ʾ���ж�����������j-1�ķ������ڶ����ʾѡһ����ֵΪj�Ķ����ķ���
// ����������long longƴ������
// �߽�: dp[i][1] = 1, dp[0][j] = 0;

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int maxk = 105;

long long dp[maxn][maxk][2];
const long long mod = 100000000000000000;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif	
	int n,k;
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		dp[i][1][0] = 0;
		dp[i][1][1] = 1;
	}
	for(int j=0;j<=k;++j){
		dp[0][j][0] = 0;
		dp[0][j][1] = 1;
	}
	for(int i=1;i<=n;++i){
		for(int j=2;j<=k;++j){
			if(i - j >= 0){
				dp[i][j][1] = dp[i][j-1][1] + dp[i-j][j][1];
				dp[i][j][0] = dp[i][j-1][0] + dp[i-j][j][0];
			}else{
				dp[i][j][1] = dp[i][j-1][1];
				dp[i][j][0] = dp[i][j-1][0];
			}
			if(dp[i][j][1] >= mod){
				long long plus = dp[i][j][1] / mod;
				dp[i][j][1] %= mod;
				dp[i][j][0] += plus;
			}
			//cout<<"i="<<i<<" j="<<j<<" dp="<<dp[i][j][1]<<endl;
		}
	}
	
	if(dp[n][k][0] > 0){
		//cout<<dp[n][k][0]<<dp[n][k][1]<<endl;
		cout<<dp[n][k][0];
		long long a = dp[n][k][1];
		a *= 10;
		while(a < mod){ //ǰ����
			cout<<"0";
			a *= 10;
		}
		cout<<dp[n][k][1]<<endl;
	}else{
		cout<<dp[n][k][1]<<endl;
	}
	return 0;
}