#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double rate=0.,initial=0.,year=0.;
	cin>>rate>>initial>>year;
	double result=pow((1.+rate/100.),year)*initial;
	cout<<int(result);
	return 0;
}