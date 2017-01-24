//Prim
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int inf = 0xffffff;

int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n;


int prim(){
	for(int i=0;i<n;++i){
		mincost[i] = inf;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;
	while(true){
		int v = -1;
		for(int u=0;u<n;++u){
			if(!used[u] && (v == -1 || mincost[u] < mincost[v])){
				v = u;
			}
		}
		if(v==-1){
			break;
		}
		used[v] = true;
		res += mincost[v];
		for(int u=0;u<n;++u){
			mincost[u] = min(mincost[u],cost[v][u]);
		}
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	while(cin>>n){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>cost[i][j];
			}
		}
		cout<<prim()<<endl;
	}
	return 0;
}