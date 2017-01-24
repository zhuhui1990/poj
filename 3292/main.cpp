//É¸·¨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 1000500;

int res[maxn];
int hprime[maxn]={0};

void getHPrimes(){
//	memset(hprime,0,sizeof(hprime));
	for(int i=5;i<=maxn;i+=4){
		for(int j=5;j<=maxn;j+=4){
			if(i*j > maxn){
				break;
			}
			if(hprime[i] == 0 && hprime[j] == 0){
				hprime[i*j] = 1;
			}else{
				hprime[i*j] = -1;
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=maxn;++i){
		if(hprime[i] == 1){
			++cnt;
		}
		res[i] = cnt;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	getHPrimes();
	while(cin>>n && n){
		cout<<n<<" "<<res[n]<<endl;
	}
	return 0;
}