//Floyd-Warshall
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 305;
int dp[maxn][maxn];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif 
	int n,m;
	cin>>n>>m;
	int mm;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j] = maxn;
		}
	}
	for(int i=0;i<m;++i){
		cin>>mm;
		vector<int> v(mm);
		for(int j=0;j<mm;++j){
			cin>>v[j];
		}
		for(int j=0;j<mm;++j){
			for(int k=0;k<mm;++k){
				if(j != k){
					dp[v[j]][v[k]] = 1;
					dp[v[k]][v[j]] = 1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		dp[i][i] = 0;
	}
	/*
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<"i="<<i<<" j="<<j<<" dp[i][j]="<<dp[i][j]<<endl;
		}
	}
	*/
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int min = 305;
	for(int i=1;i<=n;++i){
		int sum = 0;
		for(int j=1;j<=n;++j){
			sum += dp[i][j];
		}
		if(sum < min){
			min = sum;
		}
	}
	cout<<min*100/(n-1)<<endl;
	return 0;
}