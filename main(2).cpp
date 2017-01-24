#include <iostream>
#include <cmath>

using namespace std;


bool isprime(int a){
	bool flag=true;
	int i;
	if(a==1)
		return false;
	if(a==2)
		return true;
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

	int a,d,n;
	int count;
	while(cin>>a>>d>>n && a && d && n){
		int i=a;
		count=0;
		for(;count<n;i+=d){
			if(isprime(i))
				count++;
		}
		cout<<i-d<<endl;	
	}
	return 0;


}