#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	vector<int> n1(n,0),n2(n,0);
	for (int i=0;i!=n;++i)
	{
		cin>>n1[i]>>n2[i];
	}

	for (int i=0;i!=n;++i)
	{
		if(n1[i]<n2[i])
		{
			cout<<"NO BRAINS"<<endl;
		}
		else
		{
			cout<<"MMM BRAINS"<<endl;
		}
	}
	return 0;
}