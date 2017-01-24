#include <iostream>

using namespace std;

int main()
{
	int n=0;
	int count=0,total=0,today=0;
	while(cin>>n&&n)
	{
		count=0;
		today=1;
		total=0;
		for (int i=1;i<=n;++i)
		{
			total+=today;
			++count;
			if(count == today)
			{
				count=0;
				++today;
			}
		}
		cout<<n<<" "<<total<<endl;
	}
}