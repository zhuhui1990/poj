#include <iostream>
#include <cmath>
#define N 1005

using namespace std;


int main(){
	int n;
	int temp;
	int aver;
	int max,min;
	while(cin>>n && n){
		max=0;
		min=10000000;
		aver=0;
		for(int i=0;i<n;++i){
			cin>>temp;
			aver+=temp;
			if(temp>max) 
				max=temp;
			if(temp<min)
				min=temp;
		
		}
		aver-=max+min;
		aver/=n-2;	
		cout<<aver<<endl;
		
	}


}

