#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool cmp(const char &a,const char &b){
	char la=tolower(a);
	char lb=tolower(b);
	if(la!=lb){
		return la<lb;
	}else{
		return a<b;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		sort(s.begin(),s.end(),cmp);
		cout<<s<<endl;
		while(next_permutation(s.begin(),s.end(),cmp)){
			cout<<s<<endl;
		}
	}


	return 0;
}