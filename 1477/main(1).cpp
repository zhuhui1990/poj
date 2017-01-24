#include <iostream>
#define N 1005
using namespace std;

int main(){
	int n;
	int a[N];
	int sum;
	int res;
	int cnt=0;
	while(cin>>n && n){
		cnt++;
		sum=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		sum/=n;
		res=0;
		for(int i=0;i<n;++i){
			if(a[i]>sum)
				res+=a[i]-sum;
		}
		cout<<"Set #"<<cnt<<endl;
		cout<<"The minimum number of moves is "<<res<<"."<<endl;
		cout<<endl;
	}

	return 0;
}