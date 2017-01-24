#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;


int main(){

	char a,b,c;
	float a1,b1,c1;
	float e,h;
	
	cout<<fixed<<setprecision(1);
	
	while(cin>>a && a!='E'){
		cin>>a1>>b>>b1;
		//cout<<a<<" "<<a1<<" "<<b<<" "<<b1<<endl;		
		if(a=='T' && b=='D'){
			e=6.11*exp(5417.7530*((1/273.16)-(1/(b1+273.16))));
			h=0.5555*(e-10.0);
			c1=a1+h;
			cout<<"T "<<a1<<" D "<<b1<<" H "<<c1<<endl;
		}
		if(a=='D' && b=='T'){
			e=6.11*exp(5417.7530*((1/273.16)-(1/(a1+273.16))));
			h=0.5555*(e-10.0);
			c1=b1+h;
			cout<<"T "<<b1<<" D "<<a1<<" H "<<c1<<endl;
		}		
		if(a=='T' && b=='H'){
			h=b1-a1;
			e=h/0.5555+10.0;
			c1=1/(1/273.16 -log(e/6.11)/5417.7530) - 273.16;
			cout<<"T "<<a1<<" D "<<c1<<" H "<<b1<<endl;
		}
		if(a=='H' && b=='T'){
			h=a1-b1;
			e=h/0.5555+10.0;
			c1=1/(1/273.16 -log(e/6.11)/5417.7530) - 273.16;
			cout<<"T "<<b1<<" D "<<c1<<" H "<<a1<<endl;
		}
		if(a=='D' && b=='H')  {
			e=6.11*exp(5417.7530*((1/273.16)-(1/(a1+273.16))));
			h=0.5555*(e-10.0);
			c1=b1-h;
			cout<<"T "<<c1<<" D "<<a1<<" H "<<b1<<endl;
		}
		if(a=='H' && b=='D'){
			e=6.11*exp(5417.7530*((1/273.16)-(1/(b1+273.16))));
			h=0.5555*(e-10.0);
			c1=a1-h;
			cout<<"T "<<c1<<" D "<<b1<<" H "<<a1<<endl;
		}


	}
	
	
	return 0;
}