#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int a[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	int n,ss;
	while(kase--){
		cin>>n>>ss;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		int res = n+1;
		int s=0,t=0,sum=0;
		while(true){
			while(t<n && sum < ss){
				sum += a[t++];
			}
			if(sum < ss){
				break;
			}
			res = min(res,t-s);
			sum -= a[s++];
		}
		if(res>n){
			res = 0;
		}
		cout<<res<<endl;
	}
	return 0;
}