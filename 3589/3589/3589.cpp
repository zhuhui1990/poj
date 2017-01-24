#include <iostream>
#include <string>

using namespace std;

int main(){

	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		string x,y;
		cin>>x>>y;
		int a=0,b=0;
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				if(x[j]==y[k]){
					if(j==k){
						a++;
					}else{
						b++;
					}
				}
			}
		}
		cout<<a<<"A"<<b<<"B"<<endl;
	}


	return 0;
}