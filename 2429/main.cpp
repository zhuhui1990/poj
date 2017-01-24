#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long gcd(const long long& a,const long long& b){
	if(b == 0){
		return a;
	}
	return (b,a%b);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	long long a,b;
	while(scanf("%lld %lld",&a,&b)==2){
		long long c = b/a;
		//long long d = sqrt(c);
		long long d = 1;
		while(d*d < c){
			++d;
		}
		--d;
		for(long long i = d;i>=1;--i){
			if(c%i == 0 && gcd(c/i,i) == 1){
				//cout<<a*i<<" "<<b/i<<endl;
				printf("%lld %lld\n",a*i,b/i);
				break;
			}
		} 
	}
	return 0;
}