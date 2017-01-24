#include <iostream>
#include <vector>
#define LARGE 705
//#include <math.h>
using namespace std;

int main()
{
	double eps=1e-14;
	int n;
	while(cin>>n&&n) //必须这么写，因为1.读入的数据可能不止一组，2.cin>>n返回值是cin的状态而非n
	{
	vector<int> x(LARGE,0),y(LARGE,0); 
	for(int i=0;i!=n;++i)
	{
		cin>>x[i]>>y[i];
	}
	int nn=0;
	//cin>>nn;
	int count=0,max=0;
	int a=0,b=0;
	for(int i=0;i!=n;++i)
	{
		for (int j=i+1;j!=n;++j)
		{
			count=2;
			for (int k=j+1;k!=n;++k)
			{
				a=(y[i]-y[k])*(x[j]-x[k]);
				b=(y[j]-y[k])*(x[i]-x[k]);
				if(a==b)
				{
					++count;
				}
			}
			if(max<count)
			{
				max=count;
			}
		}
	}
	cout<<max<<endl;
	}
	//system("pause");
	return 0;
}