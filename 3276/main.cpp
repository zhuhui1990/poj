#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10005;

int n;
int dir[maxn];
int f[maxn];

int calc(int k){
	memset(f,0,sizeof(f));
	int res = 0;
	int sum = 0;
	for(int i=0;i+k<=n;++i){
		if((dir[i]+sum)%2!=0){
			++res;
			f[i] = 1;
		}
		sum += f[i];
		if(i-k+1>=0){
			sum -= f[i-k+1];
		}
	}
	for(int i=n-k+1;i<n;++i){
		if((dir[i]+sum)%2!=0){
			return -1;
		}
		if(i-k+1>=0){
			sum -= f[i-k+1];
		}
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	char c;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>c;
		dir[i] = c=='B'? 1 : 0;
	}
	int kk=1,min = n;
	for(int k=1;k<=n;++k){
		int m = calc(k);
		if(m>=0 && m < min){
			min = m;
			kk = k;
		}
	}
	cout<<kk<<" "<<min<<endl;
	return 0;
}