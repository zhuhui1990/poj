#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1005;
const int inf = 0xffff;
int a[maxn],s[maxn];

int binary_search(int s[],int digit,int length){
	int left = 0, right = length, mid;
	while(right != left){
		mid = (left+right)/2;
		if(digit == s[mid]){
			return mid;
		}else if(digit < s[mid]){
			right = mid;
		}else{
			left = mid+1;
		}
	}
	return left;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	s[0] = -1;
	int len = 1;
	for(int i=1;i<=n;++i){
		s[len] = inf;
		int j = binary_search(s,a[i],len);
		if(j == len){
			++len;
		}
		s[j] = a[i];
	}
	printf("%d\n",len-1);
	return 0;
}