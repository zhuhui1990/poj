#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string s;
	while(getline(cin,s) && s!="#"){
		int size=s.size();
		int sum=0;
		for(int i=0;i<size;++i){
			if(s[i]!=' '){
				sum+=(i+1)*(s[i]-'A'+1);
			}
		}
		cout<<sum<<endl;
	}


	return 0;
}