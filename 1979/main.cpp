#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 25;
char array[maxn][maxn];
bool visited[maxn][maxn];
int res;

bool isvalid(int x,int y,int w,int h){
	return (x>=0 && x<h && y>=0 && y<w);
}


void dfs(int x,int y,int w,int h){
	//cout<<"x="<<x<<" y="<<y<<endl;
	++res;
	visited[x][y] = true;
	
	int x1[4]={x-1,x,x,x+1};
	int y1[4]={y,y-1,y+1,y};
	for(int i=0;i<4;++i){
		if(isvalid(x1[i],y1[i],w,h) && !visited[x1[i]][y1[i]] && array[x1[i]][y1[i]] == '.'){
				dfs(x1[i],y1[i],w,h);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int w,h;
	int si,sj;
	while(cin>>w>>h && (w != 0 || h != 0)){
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				visited[i][j] = false;
				cin>>array[i][j];
				if(array[i][j] == '@'){
					si = i;
					sj = j;
				}
			}
		}
		//cout<<"si="<<si<<" sj="<<sj<<" w="<<w<<" h="<<h<<endl;
		res = 0;
		dfs(si,sj,w,h);
		cout<<res<<endl;
	}
	return 0;
}