//̰��
//֤����
/*
����ţa��b������Ϊa��b����λʱ��Ե��Ļ�Ϊda��db��

���Ƚ�a�˻�ţ����a��b��ͬ�Ե��Ļ���ya = a * da + (2 * a + b) * db
�Ƚ�b�˻�ţ����a��b��ͬ�Ե��Ļ�yb = b * db + (2 * b + a) * da
yb - ya = 2 * (b * da - a * db)
      ��yb > ya, ��(b * da)/(a * db) > 1����(b/db)>(a/da)ʱ�����Ƚ�a�˻�ţ��ʱ��϶̡�
      ͬ����yb < ya�� ��(b/db)<(a/da)ʱ���ֽ�b�˻�ȥʱ��϶̡�
      ��ya == ybʱ�����ĸ���һ����
���ԣ����Խ�(x/dx)��Ϊ���߱��������ֵ��С�����˻�ȥ��
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