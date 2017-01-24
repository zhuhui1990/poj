//我们定义dp [ i ] [ j ] 为区间 i 到 j 变成回文的最小代价。
//那么对于dp【i】【j】有三种情况
//首先：对于一个串如果s【i】==s【j】，那么dp【i】【j】=dp【i+1】【j-1】
//其次：如果dp【i+1】【j】是回文串，那么dp【i】【j】=dp【i+1】【j】+min（add【i】，del【i】）；
//最后，如果dp【i】【j-1】是回文串，那么dp【i】【j】=dp【i】【j-1】 + min（add【j】，del【j】）；

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2005;
const int maxk = 255;
const int inf = 0xffffff;

int dp[maxn][maxn];
char s[maxn];
int add[maxk];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	char c;
	int a,b;
	for(int i=0;i<n;++i){
		cin>>c>>a>>b;
		//cout<<"c="<<c<<endl;
		add[c] = a < b ? a : b;
	}
	
	memset(dp,0,sizeof(dp));
	for(int k=1;k<m;++k){
		for(int i=0,j=k;j<m;++i,++j){ //i,j的差为k
			dp[i][j] = inf;
			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1];
			}else{
				dp[i][j] = min(dp[i+1][j] + add[s[i]],dp[i][j]);  
        dp[i][j] = min(dp[i][j-1] + add[s[j]],dp[i][j]);  
			}
		}
	}
	printf("%d\n",dp[0][m-1]);
	return 0;
}