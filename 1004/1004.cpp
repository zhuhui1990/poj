#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


int main()
{
	vector<double> rawdata(12,0.);
	double result=0.;
	
	for (vector<double>::size_type i=0;i!=12;++i)
	{
		cin>>rawdata[i];
		result+=rawdata[i];
	}
	
	result=result/12.;
	
	//output
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"$"<<result<<endl;
	
	return 0;
}