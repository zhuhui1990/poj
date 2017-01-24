// dp[i][j] := ��ǰi��Ӳ�Ҵճ�jʱ��i��Ӳ�������ʣ����ٸ���-1��ʾ�䲻������
//            ���dp[i - 1][j] >= 0(ǰi-1�������Դճ�j����ô��i���������ò���)ֱ��ΪC[i]
// dp[i][j] =  ���j < A[i]����dp[i][j - a[i]] <=0 (���̫����������С������ʱ����ù��ˣ�-1
//            ����������i�����õ�һ���� dp[i][j-a[i]] - 1
// ���ͳ��һ��dp�����n��>=0�ĸ�����֪������
// ����ʡ����һά

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
				else if (j < a[i]						// ��һ���ͳ�����������
						|| dp[j - a[i]] <= 0){		// ���ձ�jС������ʱ�������ˣ���ʱ����������
					dp[j] = -1;
				}
				else{
					dp[j] = dp[j - a[i]] - 1;		// ������һ����i��Ӳ��
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