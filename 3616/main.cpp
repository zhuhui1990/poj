//���Ȱ���ÿ������Ľ���ʱ�������ٽ���Ԥ���������ÿ�������໥���ݵ���������±걣����P�����
//״̬�� dp[i]=max{ dp[i-1],dp[p[i]]+w[i] } 

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxm = 1005;

struct Interval{
	int start,end,efficiency;
	bool operator < (const Interval& rhs) const{
		return end < rhs.end;
	} 
};

Interval interval[maxm];
int last[maxm]; //��Ӧ���뵱ǰ������ݵ���������±�
int dp[maxm];

bool IsCompatible(int a,int b,int r){
	if(interval[b].start>=interval[a].end+r || interval[b].end+r<=interval[a].start){
		return true;
	}
	else{
		return false;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif	
	int n,m,r;
	scanf("%d %d %d",&n,&m,&r);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&interval[i].start,&interval[i].end,&interval[i].efficiency);
	}
	sort(interval+1,interval+m+1);
	last[1] = 0;
	for(int i=m;i>1;--i){
		int k = i-1;
		while(k > 0 && !IsCompatible(i,k,r)){
			--k;
		}
		last[i] = k;
	}

	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;++i){
		dp[i] = max(dp[i-1],dp[last[i]]+interval[i].efficiency);
	}
	printf("%d\n",dp[m]);
	return 0;
}