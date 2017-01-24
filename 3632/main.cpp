#include <iostream>

using namespace std;

int main(){
	int ncase,n;
	int temp;
	cin>>ncase;
	for(int i=0;i<ncase;++i){
		cin>>n;
		int max=0,min=1000;
		for(int j=0;j<n;++j){
			cin>>temp;
			if(temp>max) max=temp;
			if(temp<min) min=temp;
		}
		cout<<2*(max-min)<<endl;
	}
	
	
	return 0;
}