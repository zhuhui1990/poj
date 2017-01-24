#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 5005;

struct Wood{
	int l,w;
	bool operator < (const Wood& rhs) const{
		if(l != rhs.l){
			return l < rhs.l;
		}else{
			return w < rhs.w;
		}
	}
};

Wood wood[maxn];
int dp[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>wood[i].l>>wood[i].w;
		}
		sort(wood,wood+n);
		memset(dp,-1,sizeof(dp));
		//¶þ·Ö²éÕÒ
		for(int i=0;i<n;++i){
			*lower_bound(dp,dp+n,wood[i].w,greater<int>())=wood[i].w;
		}
		cout << lower_bound(dp,dp+n,-1,greater<int>())-dp<< endl;
	}
	return 0;
}