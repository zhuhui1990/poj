///dp[i][j]��ʾ��i��ƻ�����µ�ʱ������j���յ������ƻ����
///dp[i][j] = max{dp[i-1][j-1],dp[i-1][j]} + ��Ti == ��ǰλ�ã�? 1 : 0

#include <iostream>
#include <cstdio>

using namespace std;

const int maxt = 1005;
const int maxw = 35;

int dp[maxt][maxw];
int tree[maxt]; //��ƻ�����Ŀ�����
int loc[maxw];  //�����Ŀ�����

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif	
	int t,w;
	scanf("%d %d",&t,&w);
	for(int i=1;i<=t;++i){
		scanf("%d",&tree[i]);
		
	}
	//if(tree[1] == 1){
		for(int i=0;i<=w;++i){
			loc[i] = ((i % 2 == 0)? 1 : 2);
		}
	//}else{
	//	for(int i=0;i<w;++i){
	//		loc[i] = ((i % 2 == 0)? 2 : 1);
	//	}
	//}
	for(int i=1;i<=t;++i){
		dp[i][0] = dp[i-1][0] + (tree[i] == loc[0] ? 1 : 0);
	}
	for(int j=1;j<=w;++j){
		for(int i=1;i<=t;++i){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + (tree[i] == loc[j] ? 1 : 0);
			//cout<<"i="<<i<<" j="<<j<<" dp[i][j]="<<dp[i][j]<<endl;
		}	
	}
	printf("%d",dp[t][w]);
	
	return 0;
}