#include <iostream>
#define N 10005
using namespace std;

int main(){
	int n,m,c;
	int a[N],b[N];
	int sum=0,max=0;
	int temp;
	int icase=0;
	while(cin>>n>>m>>c && n && m && c){
		icase++;
		sum=0,max=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<m;++i){
			b[i]=1;
		}
		for(int i=0;i<m;++i){
			cin>>temp;
			sum+=a[temp-1]*b[temp-1];
			b[temp-1]*=-1;
			if(sum > max) max=sum;
		}
		cout<<"Sequence "<<icase<<endl;
		if(max>c)
			cout<<"Fuse was blown."<<endl;
		else{
			cout<<"Fuse was not blown."<<endl;
			cout<<"Maximal power consumption was "<<max<<" amperes."<<endl;
		}
		cout<<endl;
	}
}