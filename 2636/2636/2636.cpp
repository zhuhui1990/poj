#include <iostream>
#include <vector>
#define LARGE 15
using namespace std;

int main()
{
	int ncase;
	int n1;
	cin>>ncase;
	vector<int> v1(LARGE,0);
	vector<int> res(LARGE,0);
	for (int i=0;i!=ncase;++i)
	{
		res[i]=0;
		for (int j=0;j!=LARGE;++j)
		{
			v1[j]=0;
		}
		cin>>n1;
		for (int j=0;j!=n1;++j)
		{
			cin>>v1[j];
			res[i]+=v1[j];
		}
		res[i]-=n1;
		res[i]+=1;
	}
	for (int i=0;i!=ncase;++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}