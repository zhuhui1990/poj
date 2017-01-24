#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const int maxm = 20005;

struct Edge{
	int from,to,cost;
};

Edge es[maxm];

int n,m;

int linked;

//start of union_find
int f[maxn];

void init_union_find(int n){
	for(int i=1;i<=n;++i){
		f[i] = i;
	}
}

int find(int x){
	if(f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}

void unite(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		f[fx] = fy;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}
//end of union_find

bool comp(const Edge& e1, const Edge& e2){
	return e1.cost > e2.cost;
}

int kruskal(){
	sort(es,es+m,comp);
	init_union_find(n);
	int res = 0;
	for(int i=0;i<m;++i){
		Edge& e = es[i];
		if(!same(e.from,e.to)){
			unite(e.from,e.to);
			res += e.cost;
			++linked;
		}
		//cout<<"i="<<i<<" res="<<res<<endl;
	}
	return res;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>es[i].from>>es[i].to>>es[i].cost;
	}
	linked = 1;
	int res=kruskal();
	if(linked != n){
		cout<<"-1"<<endl;
	}else{
		cout<<res<<endl;
	}
	return 0;
}