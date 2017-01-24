//贪心
//1.首先面额不小于C的硬币属于没办法节约的类型，先统统发掉。

//2.然后对硬币面额从大到小尽量凑得接近C，允许等于或不足C，但是不能超出C。

//3.接着按硬币面额从小到大凑满C（凑满的意思是允许超出一个最小面值
//此处的最小面值指的是硬币剩余量不为0的那些硬币中的最小面值），凑满之后得出了最优解，发掉，进入步骤2.
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
		//从大到小找一遍
		for(int i=0;i<n;++i){
			if(sum > 0 && coin[i].cnt > 0){
				int canuse = min(coin[i].cnt, sum/coin[i].v);//最多能用多少个
				if(canuse > 0){
					sum -= canuse * coin[i].v;
					need[i] = canuse;
				}
			}
		}
		//从小到大找一遍
		for(int i=n-1;i>=0;--i){
			if(sum > 0 && coin[i].cnt > 0){
				int canuse = min(coin[i].cnt - need[i], (sum+coin[i].v-1)/coin[i].v); //允许超出一个硬币
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
		//更新硬币数量
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