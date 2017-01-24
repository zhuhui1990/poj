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

int dist[maxn]; //��̾���
int dist2[maxn]; //�ζ̾���


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
	priority_queue<P,vector<P>,greater<P> > q; //�����ȶ��б���
	fill(dist,dist+n,inf);
	fill(dist2,dist2+n,inf);
	dist[0] = 0;
	q.push(P(0,0));	

	while(!q.empty()){
		P p = q.top();
		q.pop();
		int v = p.second, d = p.first;
		if(dist2[v] < d){  //�ȴζ�·��Ҫ��������
			continue; 
		}
		for(int i=0;i<g[v].size();++i){
			Edge &e = g[v][i];	
			int d2;
			d2 = d + e.cost;
			if(dist[e.to] > d2){ //������̾���
				swap(dist[e.to],d2); //��ʱdist[e.to]Ϊ�µ���̾���,d2Ϊ�ɵ���̾���
				q.push(P(dist[e.to],e.to)); //���ȶ����м����µ���̱�
				//�����´�Ѱ��δʹ�õľ�����С�ĵ�
			}
			if(dist2[e.to] > d2 && dist[e.to] < d2){ //���´ζ̾���
				dist2[e.to] = d2;
				q.push(P(dist2[e.to],e.to)); //���ȶ����м����µĴζ̱�
				//�´θ���ʱҲ����ʹ�þ����С�ĵ�
			}
		}
	}

	printf("%d\n",dist2[n-1]);

	return 0;
}