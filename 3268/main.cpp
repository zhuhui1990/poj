//Dijkstra

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int to,cost;
	Edge(){
	}
	Edge(int t,int c):to(t),cost(c){
	}
};

const int maxn = 1005;

vector<Edge> es1[maxn],es2[maxn];
int d1[maxn],d2[maxn];

int n;

const int inf = 0xffffff;

typedef pair<int,int> P; //first£º×î¶Ì¾àÀë£¬second£º¶¥µã±àºÅ

void dijkstra(int s,const vector<Edge>* es,int* d){
	priority_queue<P,vector<P>,greater<P> > q;
	fill_n(d+1,n,inf);
	d[s] = 0;
	q.push(P(0,s));
	while(!q.empty()){
		P p = q.top();
		q.pop();
		int v = p.second;
		//cout<<"v="<<v<<endl;
		if(d[v] < p.first){
			continue;
		}
		for(int i=0;i<es[v].size();++i){
			Edge e = es[v][i];
			if(d[e.to] > d[v]+e.cost){
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int m,x;
	cin>>n>>m>>x;
	int a,b,t;
	for(int i=0;i<m;++i){
		cin>>a>>b>>t;
		es1[a].push_back(Edge(b,t));
		es2[b].push_back(Edge(a,t));
	}
	dijkstra(x,es1,d1);
	dijkstra(x,es2,d2);
	int max = 0;
	for(int i=1;i<=n;++i){
		int cnt = d1[i]+d2[i];
		//cout<<"i="<<i<<" d1[i]="<<d1[i]<<" d2[i]="<<d2[i]<<endl;
		if(cnt > max){
			max = cnt;
		}
	}
	cout<<max<<endl;
	return 0;
}