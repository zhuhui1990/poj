#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int main()
{
	int n=0;
	string c1,c2;
	int n1=0,n2=0,n3=0,n4=0;
	int dx,dy;
	cin>>n;
	for(int i=0;i!=n;++i){
		cin>>c1>>c2;
		dx=abs(c1[0]-c2[0]);
		dy=abs(c1[1]-c2[1]);
		n1=min(dx,dy)+abs(dx-dy);
		n3= ((dx==0 || dy==0)? 1:2);
		if((dx-dy)%2 !=0){
			n4=999;
		}
		else{
			n4=(dx==dy? 1:2);
		}
		if (n3 ==1 || n4 == 1){
			n2=1;
		}else{
			n2=2;
		}
		if (dx==0 && dy==0){ //起点和终点是同一点
			n1=0;
			n2=0;
			n3=0;
			n4=0;
		}
		cout<<n1<<" "<<n2<<" "<<n3<<" ";
		if (n4 == 999){
			cout<<"Inf"<<endl;
		}else{
			cout<<n4<<endl;
		}
	}
}