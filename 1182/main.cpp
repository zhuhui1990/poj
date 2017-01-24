//²¢²é¼¯
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int father[maxn*3];
int tt[maxn],xx[maxn],yy[maxn];

void init(int n){
	for(int i=0;i<n;++i){
		father[i] = i;
	}
}


int find(int x){
	if(father[x] == x){
		return x;
	}else{
		return father[x] = find(father[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return;
	}
	father[x] = y;
}

bool same(int x, int y){
	return (find(x) == find(y));
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,k;
	int t,x,y;
	//while(cin>>n>>k){
		//cin>>n>>k;
		scanf("%d %d",&n,&k);
		init(n*3);
		int ans = 0;
		for(int i=0;i<k;++i){
			//cin>>tt[i]>>xx[i]>>yy[i];
			scanf("%d %d %d",&tt[i],&xx[i],&yy[i]);
			--xx[i];
			--yy[i];
		}
		for(int i=0;i<k;++i){
			t = tt[i];
			x = xx[i];
			y = yy[i];
			if(x<0 || x>=n || y<0 || y>=n){
				++ans;
				continue;
			}
			if(t == 1){
				if(same(x,y+n) || same(x,y+2*n)){
					++ans;
				}else{
					unite(x,y);
					unite(x+n,y+n);
					unite(x+2*n,y+2*n);
				}
			}else{
				if(same(x,y) || same(x,y+2*n)){
					++ans;
				}else{
					unite(x,y+n);
					unite(x+n,y+2*n);
					unite(x+2*n,y);
				}
			}
		}
		//cout<<ans<<endl;
		printf("%d\n",ans);
	//}
	return 0;
}