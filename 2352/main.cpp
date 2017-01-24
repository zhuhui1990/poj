//树状数组
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 32005;

int levels[maxn];
int c[maxn];

inline int lowbit(int x){
	return x & (x^(x-1));
}

int sum(int x){
	int s = 0;
	while(x > 0){
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}

void update(int pos){
	while(pos < maxn){
		++c[pos];
		pos += lowbit(pos);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;++i){
		scanf("%d %d",&x,&y);
		++levels[sum(x+1)]; //树状数组下标从1开始
		update(x+1);
	}
	for(int i=0;i<n;++i){
		printf("%d\n",levels[i]);
	}
	return 0;
}