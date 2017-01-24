#include <iostream>
#define N 4

using namespace std;

int main()
{
	int n1=0,n2=0;

	while(cin>>n1>>n2)
	{
		int t1=0,t2=0;
		if(n1>n2)
		{
			t1=n2;
			t2=n1;
		}
		else
		{
			t1=n1;
			t2=n2;
		}
		int max=0;
		for (int j=t1;j<=t2;++j)
		{
			int c=j;
			int count=1;
			while (c!=1)
			{
				if(c%2)
				{
					c=3*c+1;
					++count;
				}
				else
				{
					c/=2;
					++count;
				}
			}
			if (count>max)
			{
				max=count;
			}
		}
		cout<<n1<<" "<<n2<<" "<<max<<endl;
	}
	return 0;
}