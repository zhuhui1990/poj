#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxm = 20;
const int maxn = 20;

const int dx[5] = {-1,0,0,0,1};
const int dy[5] = {0,-1,0,1,0};

int m,n;
int tile[maxm][maxn];
int opt[maxm][maxn];
int flip[maxm][maxn];

int get(int x,int y){
	int c = tile[x][y];
	for(int d=0;d<5;++d){
		int x2 = x+dx[d], y2 = y+dy[d];
		if(x2>=0 && x2<m && y2>=0 && y2<n){
			c += flip[x2][y2];
		}
	}
	return c%2;
}

int calc(){
	for(int i=1;i<m;++i){
		for(int j=0;j<n;++j){
			if(get(i-1,j) != 0){
				flip[i][j] = 1;
			}
		}
	}
	for(int j=0;j<n;++j){
		if(get(m-1,j) != 0){
			return -1;
		}
	}
	int res = 0;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			res += flip[i][j];
		}
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	cin>>m>>n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>tile[i][j];
		}
	}
	int res = -1;
	for(int i=0;i< 1<<n;++i){
		memset(flip,0,sizeof(flip));
		for(int j=0;j<n;++j){
			flip[0][n-j-1] = (i>>j)&1;
		}
		int num = calc();
		if(num >= 0 && (res<0 || res>num)){
			res = num;
			memcpy(opt,flip,sizeof(flip));
		}
	}
	if(res<0){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				cout<<opt[i][j];
				cout<<(j+1==n ? '\n':' ');
			}
		}
	}
	return 0;
}