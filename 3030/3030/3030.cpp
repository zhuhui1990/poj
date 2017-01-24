#include <iostream>
#include <vector>
using namespace std;

struct money
{
	int nonad,ad,cost;
};

int main()
{
	int n=0;
	cin>>n;
	vector<money> cases(n);

	for (int i=0;i!=n;++i)
	{
		cin>>cases[i].nonad>>cases[i].ad>>cases[i].cost;
	}
	for (int i=0;i!=n;++i)
	{
		if(cases[i].ad-cases[i].cost > cases[i].nonad)
		{
			cout<<"advertise"<<endl;
		}
		else if(cases[i].ad-cases[i].cost < cases[i].nonad)
		{
			cout<<"do not advertise"<<endl;
		}
		else if(cases[i].ad-cases[i].cost == cases[i].nonad)
		{
			cout<<"does not matter"<<endl;
		}
		
	}
	//system("pause");
	return 0;
}