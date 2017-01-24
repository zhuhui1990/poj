#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;
int father[maxn * 2];

int find(int x){
	if(x != father[x]){
		father[x] = find(father[x]);
	}
	return father[x];
}

void init(int n){
	for(int i=0;i<=n;++i){
		father[i] = i;
	}
}

void unite(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy){
		return;
	}else{
		father[fx] = fy;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	char c;
	int a,b;
	scanf("%d",&t);
	while(t--){
		cin>>n>>m;
		init(n * 2);
		getchar();
		while(m--){
			scanf("%c%d%d%*c",&c,&a,&b);
			//cin>>c>>a>>b;
			//cout<<c<<" "<<a<<" "<<b<<endl;
			if(c == 'A'){
				if(same(a,b)){
					printf("In the same gang.\n");
				}else if(same(a,b+n)){
					printf("In different gangs.\n");
				}else{
					printf("Not sure yet.\n");
				}
			}else{
				unite(a,b+n);
				unite(a+n,b);
			}
		}
	}
	return 0;
}