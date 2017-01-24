#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string num2str(int i){
	stringstream ss;
	ss << i;
	return ss.str();
}

int str2num(string s){
	int num;
	stringstream ss(s);
	ss>>num;
	return num;
}

int main(){
	int n;
	cin>>n;
	int a,b,c;
	string s1,s2,s3;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		a=str2num(s1);
		b=str2num(s2);
		c=a+b;
		s3=num2str(c);
		reverse(s3.begin(),s3.end());
		c=str2num(s3);
		cout<<c<<endl;
	}
	return 0;
}