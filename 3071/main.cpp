//DP
//dp[i][j] := 第j轮比赛，i号队伍获胜概率
//dp[i][j] = dp[i-1][j] * sum(dp[i-1][k]*m[j][k])

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn =130; // pow(2,7) = 128
const int maxm = 8;

double p[maxn][maxn];
double dp[maxn][maxm];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	while(cin>>n && n!=-1){
		int m = 1<<n;
		for(int i=0;i<m;++i){
			for(int j=0;j<m;++j){
				scanf("%lf",&p[i][j]);
			}
			dp[i][0] = 1.;
		}
		int ans;
		for(int i=0;i<n;++i){
			ans = 0;
			for(int j=0;j<m;++j){
				double sum = 0.;
				for(int k=(1<<i);k<(1<<(i+1));++k){ //可能与j号队伍比赛的队伍循环
					sum += dp[k^j][i] * p[j][k^j]; //k^j即为可能与j号队伍比赛的所有队伍
				}
				dp[j][i+1] = dp[j][i] * sum;
				if(dp[j][i+1] > dp[ans][i+1]){
					ans = j;
				}
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}