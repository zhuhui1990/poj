#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

	double vs,r,c,w,vr;
	int n;
	cin>>vs>>r>>c>>n;
	for(int i=0;i<n;++i){
		cin>>w;
		vr=vs*c*r*w/sqrt(1.+c*c*r*r*w*w);
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<vr<<endl;
	}
	

}