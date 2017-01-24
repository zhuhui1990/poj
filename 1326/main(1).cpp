#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	float c;
	char d;
	float sum=0.;
	while(cin>>a && a!="#"){
		if(a == "0"){
			cout<<int(sum+0.5)<<endl;
			sum=0.;
		}else{
			cin>>b>>c>>d;
			if(d=='F'){
				sum+=2.*c;
			}else if(d=='B'){
				sum+=int(1.5*c+0.5);
			}else if(d=='Y'){
				if (c<500.){
					sum+=500.;
				}else{
					sum+=c;
				}
			}
		}
	}
	return 0;
}