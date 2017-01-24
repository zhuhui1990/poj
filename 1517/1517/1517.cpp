#include <iostream>
#include <iomanip>

using namespace std;

int fact(int i);

int main()
{
	cout<<setiosflags(ios::fixed)<<setprecision(9);
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;

	double result=0;;
	for (int i=0;i<=9;++i)
	{
		result+=1./fact(i);
		cout<<i<<" "<<result<<endl;
	}

	system("pause");

	return 0;
}

int fact(int i)
{
	int fac=1;
	for (int j=1;j<=i;++j)
	{
		fac*=j;
	}
	return fac;
}