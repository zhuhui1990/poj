//���ر�������������
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = 40005;
const int maxm = 405;

int f[2][maxn]; //��������
pair<int,int> q[maxn]; //�������У�first�����Ž⣬second���ݻ�

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
		int v,w,m; //��ֵ������������
		v = block[i].h;
		w = block[i].h;
		m = block[i].c;
		int vv = block[i].a;
		for(int mod = 0;mod<w;++mod){
			int l=0,r=0; //�������У����׶�β
			for(int j=0;mod+j*w<=vv;++j){
				while(r>l && (f[pre][mod+j*w]-j*v > q[r-1].first)){
					--r;
				}
				q[r++] = make_pair(f[pre][mod+j*w]-j*v,j);
				if(r-l >0 && j-q[l].second > m){
					//���в�Ϊ�գ������Ž��Ӧ��ȱ���޷�����������
					++l;
				}
				f[cur][mod+j*w] = q[l].first+j*v;
			}
		}
	}
	cout<<*max_element(f[cur],f[cur]+block[k-1].a+1)<<endl;
	return 0;
}