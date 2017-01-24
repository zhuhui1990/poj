#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 25;
const int inf = 0xffffff;
int array[maxn][maxn];

int fx[4]={-1, 0, 0, 1};
int fy[4]={ 0,-1, 1, 0};
int res;
bool flag; //是否到达
int w,h;

bool isvalid(int x,int y){
	return (x>=0 && x<h && y>=0 && y<w);
}

void dfs(int si,int sj,int cnt){
	if(cnt > 10){
		return;
	}
	for(int i=0;i<4;++i){ //向四个方向运动
		int tx = si + fx[i];
		int ty = sj + fy[i];
		if(array[tx][ty] == 1 || !isvalid(tx,ty)){ //撞墙或掉下去
			continue;
		}
		while(isvalid(tx,ty)){
			if(array[tx][ty] == 3){
				res = cnt < res? cnt:res;
				return;
			}
			if(array[tx][ty] == 1){
				array[tx][ty] = 0;
				dfs(tx-fx[i],ty-fy[i],cnt+1);
				array[tx][ty] = 1;
				break;
			}
			tx += fx[i];
			ty += fy[i];
		}
	}	
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	while(scanf("%d %d",&w,&h) && (w!=0 || h!=0)){
		int si,sj;
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				scanf("%d",&array[i][j]);
				if(array[i][j] == 2){
					si = i;
					sj = j;
				}
			}
		}
		res = inf;
		flag=false;
		dfs(si,sj,1);
		if(res > 10)
			res = -1;
		printf("%d\n",res);
	}
	return 0;
}