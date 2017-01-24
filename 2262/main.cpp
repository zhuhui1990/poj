#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int a){
	bool flag=true;
	int i;
	for(i=2;i<=sqrt(double(a));i++)
	{
		if(a%i==0)
		{
			flag=false;
			break;
		}
	}
	return flag;
}

int main(){
	int a;
	while(cin>>a && a){
		for(int i=3;i<=a/2;i+=2){
			if(isprime(i) && isprime(a-i)){
				cout<<a<<" = "<<i<<" + "<<a-i<<endl;
				break;
			}
		}
	}
}