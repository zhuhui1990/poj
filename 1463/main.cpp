#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1501;
int pre[maxn],childcnt[maxn],root,n;
int dp[maxn][2];

void DP(int root){
	int dp0 = 0,dp1 = 0;
	if(childcnt[root] == 0){
		dp[root][0] = 0;
		dp[root][1] = 1;
		//cout<<"root="<<root<<" dp[0]="<<dp[root][0]<<" dp[1]="<<dp[root][1]<<endl;
		return;
	}
	for(int i=0;i<n;++i){
		if(pre[i] == root){
			DP(i);
			dp1 += min(dp[i][1],dp[i][0]);
			dp0 += dp[i][1];
		}
	}
	dp[root][1] = dp1+1;
	dp[root][0] = dp0;
	//cout<<"root="<<root<<" dp[0]="<<dp[root][0]<<" dp[1]="<<dp[root][1]<<endl;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int father,m,child;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		root = -1;
		memset(childcnt,-1,sizeof(childcnt));
		for(int i=0;i<n;++i){
			scanf("%d:(%d)",&father,&m);
			childcnt[father] = m;
			if(root == -1){
				root = father;
			}
			while(m--){
				scanf("%d",&child);
				pre[child] = father;
				if(child == root){
					root = father;
				}
			}
		}
		//cout<<"root="<<root<<endl;
		DP(root);
		printf("%d\n",min(dp[root][0],dp[root][1]));
	}
	
	return 0;
}