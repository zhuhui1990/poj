#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

const int maxp = 1000000+5;
int a[maxp];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int p;
	cin>>p;
	for(int i=0;i<p;++i){
		scanf("%d",&a[i]);
	}
	set<int> all;
	for(int i=0;i<p;++i){
		all.insert(a[i]);
	}
	int n = all.size();
	int s=0,t=0,num=0;
	map<int,int> count;
	int res = p;
	while(true){
		while(t<p && num < n){
			if(count[a[t++]]++ == 0){
				++num;
			}
		}
		//cout<<"s="<<s<<" t="<<t<<" num="<<num<<" n="<<n<<endl;
		if(num < n){
			break;
		}
		res = min(res,t-s);
		if(--count[a[s++]] == 0){
			--num;
		}
	}
	printf("%d\n",res);
	return 0;
}