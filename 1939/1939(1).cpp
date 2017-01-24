#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector<double> x(n),y(n);
		for(int i=0;i!=n;++i){
			cin>>x[i]>>y[i];
		}
		cout<<setiosflags(ios::fixed)<<setprecision(6);
		cout<<n<<" ";
		for(int i=0;i!=n-1;++i){
			cout<<0.5*(x[i]+x[i+1])<<" "<<0.5*(y[i]+y[i+1])<<" ";
		}
		cout<<0.5*(x[0]+x[n-1])<<" "<<0.5*(y[0]+y[n-1]);
		cout<<endl;
		
	}
	return 0;
}