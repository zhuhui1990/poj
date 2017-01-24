//f(n,k) = k! *((k+1)^(n-k)-k^(n-k)) % mod

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const long long mod = 20100713LL;
const int maxn = 1000005;

long long jiecheng[maxn];

void solve(){
	jiecheng[0] = jiecheng[1] = 1;
	for(int i=2;i<maxn;++i){
		jiecheng [i] = jiecheng[i-1] * i % mod;
	}
}

long long multimod(long long x,long long n,long long mod){
	long long tmp = x, res = 1LL;
	while(n){
		if(n&1LL){
			res *= tmp;
			res %= mod;
		}
		tmp *= tmp;
		tmp %= mod;
		n >>= 1;
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif 
	int t,n,k;
	long long ans1,ans2,ans;
	solve();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		//cout<<"n="<<n<<" k="<<k<<endl;
		if(k == 0){
			printf("1\n");
			continue;
		}
		ans1 = ans2 = jiecheng[k];
		ans1 *= multimod(k+1,n-k,mod);
		ans1 %= mod;
		ans1 += mod;
		ans2 *= multimod(k,n-k,mod);
		ans2 %= mod;
		ans =(ans1-ans2)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}