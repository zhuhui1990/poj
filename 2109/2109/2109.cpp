#include <iostream>
#include <math.h>
using namespace std;

//ֱ����double���ͽ������

int main()
{
	double n=0.,p=0.;
	double result=0.;
	while (cin>>n>>p)
	{
		result=pow(p,1./n);
		cout<<result<<endl;
	}
	return 0;
}