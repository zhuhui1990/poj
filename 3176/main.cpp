#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 405;
int data[maxn][maxn];
int res[maxn];
int oldres[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	//cout<<"n="<<n<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){
			cin>>data[i][j];
			//cout<<"i="<<i<<" j="<<j<<data[i][j]<<endl;
		}
	}
	for(int i=0;i<n;++i){
		oldres[i] = data[n-1][i];
	}
	for(int i=n-2;i>=0;--i){
		for(int j=0;j<=i;++j){
			res[j] = data[i][j]+max(oldres[j],oldres[j+1]);
		}
		for(int j=0;j<=i;++j){
			oldres[j] = res[j];
		}
	}
	cout<<res[0]<<endl;
	return 0;
}