//Bellman-Ford ÅÐ¸ºÈ¦
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 505;

int d[maxn];

struct Edge{
	int from,to;
	int cost;
	Edge(){
	}
	Edge(int f,int t,int c):from(f),to(t),cost(c){
	}
};

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int f;
	cin>>f;
	while(f--){
		int n,m,w;
		cin>>n>>m>>w;
		memset(d,0,sizeof(d));
		vector<Edge> es;
		int s,e,t;
		for(int i=0;i<m;++i){
			cin>>s>>e>>t;
			es.push_back(Edge(s,e,t));
			es.push_back(Edge(e,s,t));
		}
		for(int i=0;i<w;++i){
			cin>>s>>e>>t;
			es.push_back(Edge(s,e,-t));
		}
		bool flag = false;
		for(int i=0;i<n;++i){
			for(int j=0;j<2*m+w;++j){
				Edge& e = es[j];
				if(d[e.to] > d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					if(i == n-1){
						flag = true;
					}
				}
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}