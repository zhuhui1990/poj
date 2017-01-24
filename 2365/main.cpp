#include <iostream>
#include <cmath>
#include <iomanip>
#define N 1005
#define PI 3.14159265359

using namespace std;

int main(){
	int n;
	double r;
	double x[N],y[N];
	double res=0;
	
	cin>>n>>r;
	res+=2*PI*r;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n-1;++i){
		res+=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));	
	}
	
	res+=sqrt((x[0]-x[n-1])*(x[0]-x[n-1])+(y[0]-y[n-1])*(y[0]-y[n-1]));	
	
	cout<<fixed<<setprecision(2)<<res<<endl;

}