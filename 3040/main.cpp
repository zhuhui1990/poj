//̰��
//1.������С��C��Ӳ������û�취��Լ�����ͣ���ͳͳ������

//2.Ȼ���Ӳ�����Ӵ�С�����յýӽ�C��������ڻ���C�����ǲ��ܳ���C��

//3.���Ű�Ӳ������С�������C����������˼��������һ����С��ֵ
//�˴�����С��ֵָ����Ӳ��ʣ������Ϊ0����ЩӲ���е���С��ֵ��������֮��ó������Ž⣬���������벽��2.
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int max1 = 25;
const int inf = 0xffffff;

struct Coin{
	int v;
	int cnt;
	bool operator < (const Coin& rhs) const{
		return v > rhs.v;
	}
};

Coin coin[max1];
int need[max1];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,c;
	cin>>n>>c;
	int res = 0;
	for(int i=0;i<n;++i){
		cin>>coin[i].v>>coin[i].cnt;
	}
	for(int i=0;i<n;++i){
		if(coin[i].v >= c){
			res += coin[i].cnt;
			coin[i].cnt = 0;
		}
	}
	sort(coin,coin+n);
	while(true){
		int sum = c;
		memset(need, 0, sizeof(need));
		//�Ӵ�С��һ��
		for(int i=0;i<n;++i){
			if(sum > 0 && coin[i].cnt > 0){
				int canuse = min(coin[i].cnt, sum/coin[i].v);//������ö��ٸ�
				if(canuse > 0){
					sum -= canuse * coin[i].v;
					need[i] = canuse;
				}
			}
		}
		//��С������һ��
		for(int i=n-1;i>=0;--i){
			if(sum > 0 && coin[i].cnt > 0){
				int canuse = min(coin[i].cnt - need[i], (sum+coin[i].v-1)/coin[i].v); //������һ��Ӳ��
				if(canuse > 0){
					sum -= canuse * coin[i].v;
					need[i] += canuse;
				}
			}
		}
		
		
		if(sum > 0){
			break;
		}
		int addup = inf;
		for(int i=0;i<n;++i){
			if(need[i] == 0){
				continue;
			}
			addup = min(addup,coin[i].cnt / need[i]);
		}
		res += addup;
		//����Ӳ������
		for(int i=0;i<n;++i){
			if(need[i] == 0){
				continue;
			}
			coin[i].cnt -= addup * need[i];
		}
		
	}
	cout<<res<<endl;
	return 0;
}