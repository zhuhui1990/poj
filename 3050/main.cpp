#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<int> ht;
int map[5][5];
//bool visited[5][5];
int fx[4] = {-1, 0, 0, 1};
int fy[4] = { 0,-1, 1, 0};
int res;

void dfs(int x,int y,int depth){
	if(depth == 6){
		if(ht.find(res) == ht.end()){
			ht.insert(res);
		}
	}else{
		for(int i=0;i<4;++i){
			int xx = x+fx[i];
			int yy = y+fy[i];
			int oldres = res;
			if(xx>=0 && xx<5 && yy>=0 && yy<5){
				res = res*10+map[xx][yy];
				//visited[xx][yy] = true;
				dfs(xx,yy,depth+1);
				res = oldres;
				//visited[xx][yy] = false;
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cin>>map[i][j];
			//visited[i][j] = false;
		}
	}
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			//cout<<"i="<<i<<" j="<<j<<endl;
			//memset(visited,false,25);
			//visited[i][j] = true;
			res = map[i][j];
			dfs(i,j,1);
		}
	}
	cout<<ht.size()<<endl;
	return 0;
}