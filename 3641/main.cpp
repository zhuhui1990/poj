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

bool isprime(ll a){
	if(a==0 || a==1){
		return false;
	}
	for(ll i=2;i*i<=a;++i){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	ll p,a;
	while(cin>>p>>a && (p+a)!=0){
		//cout<<"p="<<p<<" a="<<a<<endl;
		//cout<<"isprime(p)="<<isprime(p)<<endl;
		if(isprime(p)){
			cout<<"no"<<endl;
			continue;
		}
		ll b = mod_pow(a,p,p);
		if(b != a){
			cout<<"no"<<endl;
			continue;
		}
		cout<<"yes"<<endl;
	}
	return 0;
}