#include <iostream>
using namespace std;

int main()
{
	double targ;
	double start=0;
	int i=0;
	while (cin>>targ && targ !=0.00)
	{
		start=0;
		i=1;
		while(start < targ)
		{
			start+=1./(1.+i);
			++i;
		}
		cout<<i-1<<" card(s)"<<endl;
	}
	return 0;
}