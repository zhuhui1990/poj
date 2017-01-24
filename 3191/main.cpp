#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	int s[maxn];
	while(cin>>n){
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		int i=0;
		memset(s,0,sizeof(s));
		while(n){
			s[i] = n%2;
			if(n<0){
				s[i] = -s[i];
			}
			n -= s[i];
			n /= -2;
			++i;
		}
		for(int j=0;j<i;++j){
			cout<<s[i-1-j];
		}
		cout<<endl;
	}
	return 0;
}