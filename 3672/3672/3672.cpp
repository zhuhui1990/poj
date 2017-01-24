#include <iostream>
#include <string>
using namespace std;

int main(){

	int M,T,U,F,D;

	cin>>M>>T>>U>>F>>D;

	int t1=0;
	int ans=0;
	
	string x="";
	for (int i=0;i<T;++i){
		char temp;
		cin>>temp;
		x.push_back(temp);
	}


	

	int i=0;
	while(t1<M && i<x.size()){
		if(x[i]=='u'){
			t1+=U+D;
		}else if(x[i] =='f'){
			t1+=F+F;
		}else if(x[i] =='d'){
			t1+=D+U;
		}
		i++;
		ans++;
	}

	cout<<ans-1<<endl;

	return 0;
}
