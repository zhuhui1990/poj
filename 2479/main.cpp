#include <iostream>
#include <cstdio>


const int maxn = 50005;
const int inf = 0xfffffff;

int a[maxn];
int left[maxn],right[maxn]; 
//left[i]先用来保存以a[i]结尾的最大和，然后再更新成0到i的最大字段和

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		left[0] = a[0];
		for(int i=1;i<n;++i){
			left[i] = left[i-1] > 0 ? left[i-1]+a[i] : a[i];
		}
		for(int i=1;i<n;++i){
			left[i] = left[i] > left[i-1] ? left[i]:left[i-1];
		}
		right[n-1] = a[n-1];
		for(int i=n-2;i>=0;--i){
			right[i] = right[i+1] > 0? right[i+1]+a[i] : a[i];
		}
		for(int i=n-2;i>=0;--i){
			right[i] = right[i] > right[i+1]? right[i] : right[i+1];
		}
		int res = -inf;
		for(int i=1;i<n;++i){
			res = res > (left[i-1]+right[i]) ? res : left[i-1]+right[i];
		}
		printf("%d\n",res);
	};
	return 0;
}