#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int maxn = 1005;

int f[maxn];
pair<double,double> loc[maxn];

inline double dist(int i,int j){
	return (loc[i].first-loc[j].first)*(loc[i].first-loc[j].first)
		+ (loc[i].second-loc[j].second)*(loc[i].second-loc[j].second);
}

int find(int x){
	if(f[x] == x){
		return x;
	}else{
		return f[x] = find(f[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return;
	}else{
		f[x] = y;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	double d;
	cin>>n>>d;	
	for(int i=1;i<=n;++i){
		cin>>loc[i].first>>loc[i].second;
		f[i] = -1;
	}
	char c;
	int c1,c2;
	while(cin>>c){
		if(c == 'O'){
			cin>>c1;
			f[c1] = c1;
			for(int i=1;i<=n;++i){
				if(f[i] >= 0 && i != c1){
					if(dist(i,c1) <= d*d){
						unite(i,c1);
					}
				}
			}
		}else if (c == 'S'){
			cin>>c1>>c2;
			if(same(c1,c2)){
				cout<<"SUCCESS"<<endl;
			}else{
				cout<<"FAIL"<<endl;
			}
		}
	}
	return 0;
}