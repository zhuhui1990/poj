#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n;
	double res=0.;
	cout<<"Cards  Overhang"<<endl;
	while(cin>>n){
		res=0.;
		for (int i=1;i<=n;++i){
			res+=0.5/double(i);
		}
		
		cout<<setiosflags(ios::fixed)<<setw(5)<<n<<setw(10)<<setprecision(3)<<res<<endl;
	}

	return 0;
}