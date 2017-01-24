#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10005;

int c[maxn];
int y[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,s;
	long long res = 0;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;++i){
		scanf("%d %d",&c[i],&y[i]);
	}
	int loc = 0;
	while(loc < n){
		int cur = c[loc];
		res += cur * y[loc];
		int j = 1;
		while(loc+j < n && c[loc+j] >= c[loc]+s*j){
			res += s * j * y[loc+j] + cur*y[loc+j];
			++j;
		}
		loc = loc+j; 
	}
	cout<<res<<endl;
	return 0;
}