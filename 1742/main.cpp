// dp[i][j] := 用前i种硬币凑成j时第i种硬币最多能剩余多少个（-1表示配不出来）
//            如果dp[i - 1][j] >= 0(前i-1个数可以凑出j，那么第i个数根本用不着)直接为C[i]
// dp[i][j] =  如果j < A[i]或者dp[i][j - a[i]] <=0 (面额太大或者在配更小的数的时候就用光了）-1
//            其他（将第i个数用掉一个） dp[i][j-a[i]] - 1
// 最后统计一下dp数组第n行>=0的个数就知道答案了
// 可以省掉第一维

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
const int maxm = 100005;

int dp[maxm];
int a[maxn],c[maxn];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,m;
	while(scanf("%d %d",&n,&m) && (n != 0 || m != 0)){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&c[i]);
		}
		memset(dp,-1,sizeof(dp));
		
		dp[0] = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j <= m; ++j){
				if (dp[j] >= 0){
					dp[j] = c[i];
				}
				else if (j < a[i]						// 用一个就超出，不能用
						|| dp[j - a[i]] <= 0){		// 连凑比j小的数的时候都用完了，此时更加用完了
					dp[j] = -1;
				}
				else{
					dp[j] = dp[j - a[i]] - 1;		// 用上了一个第i个硬币
				}
			}
		}
		int ans = 0;
		for(int j=1;j<=m;++j){
			if(dp[j] >= 0){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}