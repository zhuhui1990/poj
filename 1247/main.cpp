#include <iostream>
#define N 35
using namespace std;

int main(){
	int n;
	int sum;
	int sum1;
	int pos;
	int a[N];
	while (cin>>n && n){
		sum=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%2 != 0){
			cout<<"No equal partitioning."<<endl;
			continue;
		}
		sum1=0;
		pos=-1;
		for(int i=0;i<n;++i){
			sum1+=a[i];
			if(sum1==sum/2){
				pos=i+1;
				break;
			}
		}
		if(pos == -1){
			cout<<"No equal partitioning."<<endl;
		}else{
			cout<<"Sam stops at position "<<pos<<" and Ella stops at position "<<pos+1<<"."<<endl;
		}
	}
	return 0;

}