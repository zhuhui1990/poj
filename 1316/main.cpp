#include <iostream>
#define N 10000
using namespace std;

int main(){
	int a[N+1000]={0};
	//for(int i=1;i<N+1000;i++){
	//	a[i]=0;	
	//}
	for(int i=1;i<N;i++){
		int k=i;
		int s=i;
		while(k>0){
			s+=k%10;
			k/=10;
		}
		a[s]=i;
	//	cout<<i<<" "<<s<<endl;
	}
	for(int i=1;i<N;i++){
		if(!a[i])
			cout<<i<<endl;
	}



	return 0;
}