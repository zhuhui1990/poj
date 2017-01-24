#include <iostream>

using namespace std;

const int maxm = 105;
const int maxn = 105;
char field[maxn][maxm];

inline bool isvalid(int x,int y,int n,int m){
	return (x >= 0 && x < n && y >= 0 && y < m);
}


void dfs(int x,int y,int n,int m){
	field[x][y] = '.';
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			if(isvalid(x+i,y+j,n,m) && field[x+i][y+j] == 'W'){
				dfs(x+i,y+j,n,m);
			}
		}
	}
}

int main(){
	int n,m;
	while(cin>>n>>m){
		int cnt = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>field[i][j];
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(field[i][j] == 'W'){
					dfs(i,j,n,m);
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}