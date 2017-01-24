#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		string s;
		int tmp;
		cin>>tmp>>s;
		if(next_permutation(s.begin(),s.end())){
			cout<<tmp<<" "<<s<<endl;;
		}else{
			cout<<tmp<<" "<<"BIGGEST"<<endl;
		}
	}
	return 0;

}