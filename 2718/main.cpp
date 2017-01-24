//brute force
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int inf = 0xffffff;
const int maxn = 15;

int a[15];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int m,n;
	char c;
	string s;
	scanf("%d",&m);
	getline(cin,s);
	for(int i=0;i<m;++i){
		n=0;
		fill(a,a+maxn,0);
		while((c=getchar())!='\n'){
			if( c >= '0' && c <= '9'){
				a[n++] = c-'0';
				//cout<<c<<endl;
			}
		}
		if(n == 1){
			printf("%d\n",a[0]);
		}else if(n == 2){
			printf("%d\n",abs(a[1]-a[0]));
		}else{
			while(a[0] == 0){
				next_permutation(a,a+n);
			}
			int ans = inf;
			int mid = (n+1)/2;
			do{
				if(a[mid]!=0){
					int x = a[0], y = a[mid];
					for(int i=1;i<mid;++i){
						x = x*10+a[i];
					}
					for(int i=mid+1;i<n;++i){
						y = y*10+a[i];
					}
					if(ans > abs(x-y)){
						ans = abs(x-y);
					}
				}
			}while(next_permutation(a,a+n));
			cout<<ans<<endl;
		}
	}
	return 0;
}