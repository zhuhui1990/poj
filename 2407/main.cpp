#include <iostream>
#include <cstdio>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,ans;
	while(cin>>n && n){
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		ans = n;
		for(int i=2;i*i<=n;++i){
			if(n%i == 0){
				ans -= ans/i;
				do{
					n /= i;
				}while(n%i == 0);
			}
		}
		if(n!=1){
			ans -= ans/n;
		}
		cout<<ans<<endl;
	}
	return 0;
}