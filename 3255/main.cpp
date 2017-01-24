#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 10005;
const int inf = 0xffffff;

struct Edge{
	int to;
	int cost;
	Edge(int v,int c): to(v),cost(c){}
};

vector<Edge> g[maxn];

typedef pair<int,int> P; //first = cost, second = v;

int dist[maxn]; //最短距离
int dist2[maxn]; //次短距离


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif 
	int n,r;
	scanf("%d %d",&n,&r);
	int u,v,cost;
	for(int i=0;i<r;++i){
		scanf("%d %d %d",&u,&v,&cost);
		g[u-1].push_back(Edge(v-1,cost));
		g[v-1].push_back(Edge(u-1,cost));
	}
	priority_queue<P,vector<P>,greater<P> > q; //用优先队列保存
	fill(dist,dist+n,inf);
	fill(dist2,dist2+n,inf);
	dist[0] = 0;
	q.push(P(0,0));	

	while(!q.empty()){
		P p = q.top();
		q.pop();
		int v = p.second, d = p.first;
		if(dist2[v] < d){  //比次短路还要长，跳过
			continue; 
		}
		for(int i=0;i<g[v].size();++i){
			Edge &e = g[v][i];	
			int d2;
			d2 = d + e.cost;
			if(dist[e.to] > d2){ //更新最短距离
				swap(dist[e.to],d2); //此时dist[e.to]为新的最短距离,d2为旧的最短距离
				q.push(P(dist[e.to],e.to)); //优先队列中加入新的最短边
				//用于下次寻找未使用的距离最小的点
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){ //更新次短距离
				dist2[e.to] = d2;
				q.push(P(dist2[e.to],e.to)); //优先队列中加入新的次短边
				//下次更新时也可能使用距离次小的点
			}
		}
	}

	printf("%d\n",dist2[n-1]);

	return 0;
}