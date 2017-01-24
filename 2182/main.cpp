//线段树
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 8005;

int small[maxn];
int ans[maxn];

struct Segment{
	int lc,rc,len;
};

Segment s[4*maxn];

void build(int root,int lc,int rc){
	s[root].lc = lc;
	s[root].rc = rc;
	s[root].len = rc - lc + 1;
	if(lc == rc){
		return;
	}
	int mid = (lc+rc)/2;
	build(2*root,lc,mid);
	build(2*root+1,mid+1,rc);
}
	
int query(int root,int k){
	--s[root].len;
	if(s[root].lc == s[root].rc){
		return s[root].lc;
	}else if( k <= s[2*root].len){
		return query(2*root,k);
	}else{
		return query(2*root+1,k-s[2*root].len);
	}
}	

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",&small[i]);
	}
	small[1] = 0;
	build(1,1,n);
	for(int i=n;i>=1;--i){ //从后往前数
		ans[i] = query(1,small[i]+1); //当前解是剩下的数了第small[i]+1小的
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}