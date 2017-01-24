//多重背包，单调队列
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = 40005;
const int maxm = 405;

int f[2][maxn]; //滚动数组
pair<int,int> q[maxn]; //单调队列，first：最优解，second：容积

struct Block{
	int h,a,c;
	bool operator < (const Block& rhs) const{
		return a < rhs.a;
	}
};

Block block[maxm];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int k;
	cin>>k;
	//cout<<"k="<<k<<endl;
	for(int i=0;i<k;++i){
		cin>>block[i].h>>block[i].a>>block[i].c;
	}
	sort(block,block+k);
	int cur = 0, pre = 1;
	for(int i=0;i<k;++i){
		//cout<<"i="<<i<<endl;
		swap(cur,pre);
		int v,w,m; //价值，重量，数量
		v = block[i].h;
		w = block[i].h;
		m = block[i].c;
		int vv = block[i].a;
		for(int mod = 0;mod<w;++mod){
			int l=0,r=0; //单调队列，队首队尾
			for(int j=0;mod+j*w<=vv;++j){
				while(r>l && (f[pre][mod+j*w]-j*v > q[r-1].first)){
					--r;
				}
				q[r++] = make_pair(f[pre][mod+j*w]-j*v,j);
				if(r-l >0 && j-q[l].second > m){
					//队列不为空，且最优解对应的缺口无法填满，出队
					++l;
				}
				f[cur][mod+j*w] = q[l].first+j*v;
			}
		}
	}
	cout<<*max_element(f[cur],f[cur]+block[k-1].a+1)<<endl;
	return 0;
}