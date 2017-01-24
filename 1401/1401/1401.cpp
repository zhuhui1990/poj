#include <iostream>

using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int targ=0;
	for (int i=0;i!=n;++i)
	{
		cin>>targ;
		int j=0,nn=1;
		while(nn<=targ)
		{
			nn*=5;
			++j;
		}
		int ans=0;
		for (int k=1;k<=j;++k)
		{
			targ/=5;
			ans+=targ;
		}
		cout<<ans<<endl;
	}


	return 0;
}