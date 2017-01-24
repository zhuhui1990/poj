#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[5];
	for (int i=0;i!=n;++i){
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		int dif=a[1]-a[0];
		if (a[2]-a[1] == dif){
			a[4]=a[3]+dif;
		}else{
			dif=a[2]/a[1];
			a[4]=a[3]*dif;
		}
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
	}

	return 0;
}