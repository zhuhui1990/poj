#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 305;
const int inf = 0xffffff;
int map[maxn][maxn];
bool visited[maxn][maxn];
int fx[4] = {-1, 0, 0, 1};
int fy[4] = { 0,-1, 1, 0};

struct Human{
	int x,y,t;
	Human(){}
	Human(int x1,int y1,int t1):x(x1),y(y1),t(t1){}
};

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int m;
	scanf("%d",&m);
	int x,y,t;
	int last = 0;
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxn;++j){
			map[i][j] = inf;
			visited[i][j] = false;
		}
	}
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&x,&y,&t);
		if(x >= 0 && y >= 0){
			map[x][y] = t < map[x][y] ? t : map[x][y];
			for(int i=0;i<4;++i){
				if(x+fx[i] >= 0 && y+fy[i] >= 0){
					map[x+fx[i]][y+fy[i]] = t < map[x+fx[i]][y+fy[i]] ? t : map[x+fx[i]][y+fy[i]];
				}
			}
			last = t > last ? t : last;
		}
	}
	if(map[0][0] <= 0){
		printf("-1\n");
		return 0;
	}
	Human h(0,0,0);
	//BFS
	queue<Human> q;
	q.push(h);
	
	while(!q.empty()){
		Human h1 = q.front();
		q.pop();
		for(int i=0;i<4;++i){
			h = h1;
			h.x += fx[i];
			h.y += fy[i];
			++h.t;
			if( h.x >= 0 && h.y >= 0 && map[h.x][h.y] > h.t && !visited[h.x][h.y]){
				//cout<<"x="<<h.x<<" y="<<h.y<<" t="<<h.t<<" last="<<last<<endl;
				visited[h.x][h.y] = true;
				if(map[h.x][h.y] > last){
					printf("%d\n",h.t);
					return 0;
				}
				q.push(h);
			}
		}
	}
	printf("-1\n");
	return 0;
}