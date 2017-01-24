#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxr = 50005;
const int maxv = 20005;

int x[maxr],y[maxr],d[maxr];

struct Edge{
	int u,v;
	int cost;
	Edge(){}
	Edge(int f,int t,int c): u(f),v(t),cost(c){}
};

Edge es[maxr];

bool comp(const Edge& lhs, const Edge& rhs){
	return lhs.cost < rhs.cost;
}

int father[maxv];

void init_union_find(int n){
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

bool same(int x,int y){
	return(find(x) == find(y));
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return;
	}
	father[x] = y ;
}

int kruskal(int v,int e){
	sort(es,es+e,comp);
	init_union_find(v);
	int res = 0;
	for(int i=0;i<e;++i){
		Edge &ee = es[i];
		//cout<<"u="<<ee.u<<" v="<<ee.v;
		//cout<<" father[u]="<<father[ee.u]<<" father[v]="<<father[ee.v]<<endl;
		if(!same(ee.u,ee.v)){
			unite(ee.u,ee.v);
			//cout<<"u="<<ee.u<<" v="<<ee.v<<" cost="<<ee.cost<<endl;
			res += ee.cost;
		}
	}
	return res;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int ncase;
	scanf("%d",&ncase);
	while(ncase){
		--ncase;
		int n,m,r;
		scanf("%d %d %d",&n,&m,&r);
		for(int i=0;i<r;++i){
			scanf("%d %d %d",&x[i],&y[i],&d[i]);
		}
		int v,e;
		v = n + m;
		e = r;
		for(int i=0;i<r;++i){
			es[i] = Edge(x[i],n+y[i],-d[i]);
		}
		printf("%d\n",10000*v+kruskal(v,e));
		
	}
	return 0;
}