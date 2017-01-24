#include <iostream>

using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int a=0,b=0;
	int res1,res2;
	for (int i=0;i!=n;++i)
	{
		cin>>a>>b;
		if(a < b)
		{
			cout<<"impossible"<<endl;
		}
		else if ( ((a+b)%2) !=0)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			res1=(a+b)/2;
			res2=(a-b)/2;
			cout<<res1<<" "<<res2<<endl;
		}
	}

		return 0;

	
}