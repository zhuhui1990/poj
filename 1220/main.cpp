#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 505;

int t[maxn],aa[maxn];
char s[maxn],d[maxn];

inline int char2int(char c){
	return c-(c<58?48:c<97?55:61);
}

inline char int2char(int a){
	return a+(a<10?48:a<36?55:61);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	int a,b;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d %d %s",&a,&b,s);
		int k = strlen(s);
		//cout<<"k="<<k<<endl;
		for(int i=k-1;i>=0;--i){
			t[k-1-i] = char2int(s[i]);
			//cout<<k-1-i<<" "<<t[k-1-i]<<endl;
		}
		int l=0;
		while(k>0){
			for(int i=k-1;i>=1;--i){ //进位
				t[i-1] += t[i]%b*a;
				t[i] /= b;
			}
			//cout<<"l="<<l<<endl;
			aa[l++] = t[0]%b; //当前的末位
			t[0] /= b; 
			while(k>0 && t[k-1] == 0){ //后面的位已处理完
				--k;
			}
		}
		d[l] = 0;
		for(int i=0;i<l;++i){
			d[l-1-i] = int2char(aa[i]);
		}
		printf("%d %s\n%d %s\n\n",a,s,b,d);
	}
	return 0;
}