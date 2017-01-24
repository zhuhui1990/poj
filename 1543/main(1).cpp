#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int b,c,d;
	bool flag;
	for(int i=2;i<=n;++i){
		for(int j=2;j<=i;++j){
			flag=false;
			for(int k=j;k<=i;++k){
				for(int l=k;l<=i;++l){
					if(i*i*i==j*j*j+k*k*k+l*l*l){
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
					//	flag=true;
					//	break;
					}
				}
				//if(flag) break;
			}
			//if(flag) continue;
		}
	}
	
	return 0;
}