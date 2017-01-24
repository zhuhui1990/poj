#include <iostream>

using namespace std;

int main(){
	int count,m,n;
	int square;
	cin>>count;
	for(int i=0;i<count;i++){
		cin>>m>>n;
		square=m*n;
		cout<<"Scenario #"<<i+1<<":"<<endl;
		if(square%2==0)
			cout<<square<<".00"<<endl;
		else
			cout<<square<<".41"<<endl;
		cout<<endl;		
	}
	return 0;
}