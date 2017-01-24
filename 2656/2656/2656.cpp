#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		int sum=0;
		int max=0;
		int day=0;
		for (int i=0;i<n;++i){
			int a,b;
			cin>>a>>b;
			sum=a+b;
			if(sum>max){
				max=sum;
				day=i+1;
			}
		}
		if(max>8){
			cout<<day<<endl;
		}else{
			cout<<0<<endl;
		}
	}

	return 0;
}