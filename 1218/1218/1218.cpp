#include <iostream>
#include <vector>
#include <bitset>
#define LARGE 10000
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	bitset<LARGE> r=0; //1´ò¿ª£¬0¹Ø±Õ
	vector<int> nn(n,0);
	for (int i=0;i!=n;++i)
	{
		cin>>nn[i];
	}
	for (int i=0;i!=n;++i)
	{
		r.reset();
		for (int j=0;j!=nn[i];++j)
		{
			r.set(j);
		}
		for (int j=2;j<=nn[i];++j)
		{
			for (int k=j-1;k<=nn[i]-1;k+=j)
			{
				r.flip(k);
			}
		}
		cout<<r.count()<<endl;
	}
	system("pause");
	return 0;
}