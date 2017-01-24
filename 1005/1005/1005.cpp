#include <iostream>
#include <vector>
#include <math.h>
#define PI 3.14159265359
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	vector<double> x(n,0.),y(n,0.);
	vector<double> r(n,0.);
	for (int i=0;i!=n;++i)
	{
		cin>>x[i]>>y[i];
		r[i]=sqrt(pow(x[i],2.)+pow(y[i],2.));
	}
	int j=1;
	for (int i=0;i!=n;++i)
	{
		j=1;
		while( sqrt(double(j)*50.*2./PI) < r[i])
		{
			++j;
		}
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<j<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	//system("pause");
	return 0;
}