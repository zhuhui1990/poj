//贪心
//证明：
/*
假设牛a、b，距离为a，b，单位时间吃掉的花为da，db。

则先将a运回牛房，a、b共同吃掉的花是ya = a * da + (2 * a + b) * db
先将b运回牛房，a、b共同吃掉的花yb = b * db + (2 * b + a) * da
yb - ya = 2 * (b * da - a * db)
      当yb > ya, 即(b * da)/(a * db) > 1，即(b/db)>(a/da)时，先先将a运回牛房时间较短。
      同理，当yb < ya， 即(b/db)<(a/da)时，现将b运回去时间较短。
      当ya == yb时，运哪个都一样。
所以，可以将(x/dx)作为决策变量，这个值较小的先运回去。
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100005;

struct Cow{
	int t,d;
	double ttd;
	bool operator < (const Cow& rhs) const{
		return ttd > rhs.ttd;
	}
};

Cow cow[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&cow[i].t,&cow[i].d);
		cow[i].ttd = double(cow[i].d)/double(cow[i].t);
	}
	sort(cow,cow+n);
	int mul = 0;
	long long res = 0;
	for(int i=0;i<n;++i){
		res += mul*cow[i].d;
		mul += cow[i].t*2;
	}
	cout<<res<<endl;
	return 0;
}