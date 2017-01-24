#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	string a,b;
	cin>>a;
	cin>>b;
	if(a.length() != b.length()){
		cout<<"NO"<<endl;	
		return 0;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	//cout<<a<<endl;
	//cout<<b<<endl;
	
	vector<int> as,bs;
	
	as.push_back(1);
	bs.push_back(1);
	
	char a0=a[0];
	char b0=b[0];
	int aa=0,bb=0;
	
	
	for(int i=1;i<a.length();++i){
		if(a[i-1] != a[i]){
			as.push_back(1);
			aa++;
		}else{
			as[aa]++;
		}
		if(b[i-1] != b[i]){
			bs.push_back(1);
			bb++;
		}else{
			bs[bb]++;
		}
	}
	
	sort(as.begin(),as.end());
	sort(bs.begin(),bs.end());

	if(as.size()!=bs.size()){
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0;i<as.size();++i){
		if(as[i]!=bs[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	return 0;
}