#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll mod_pow(ll x,ll n,ll mod){
	//cout<<"x="<<x<<" n="<<n<<endl;
	ll res = 1;
	while(n > 0){
		if(n & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int z;
	cin>>z;
	for(int i=0;i<z;++i){
		ll m;
		cin>>m;
		int h;
		cin>>h;
		ll res = 0;
		ll x,n;
		for(int j=0;j<h;++j){
			cin>>x>>n;
			res += mod_pow(x,n,m);
			res %= m;
		}
		cout<<res<<endl;
	}
	return 0;
}