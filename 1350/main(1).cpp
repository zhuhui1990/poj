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
	int a,b,c,d;
	string s1,s2,s3;
	int count=0;
	while(cin>>a && a!=-1){
		count=0;
		cout<<"N="<<a<<":"<<endl;
		s1=num2str(a);
		if(s1.length() != 4){
			cout<<"No!!"<<endl;
			continue;
		}
		sort(s1.begin(),s1.end());
		s2=s1;
		reverse(s2.begin(), s2.end()); 
		b=str2num(s1);
		c=str2num(s2);
		if(b==c){
			cout<<"No!!"<<endl;
			continue;
		}
		d=c-b;
		count++;
		cout<<c<<"-"<<b<<"="<<d<<endl;
		while(d!=0 && d!=6174){
			s1=num2str(d);
			sort(s1.begin(),s1.end());
			s2=s1;
			reverse(s2.begin(), s2.end()); 
			b=str2num(s1);
			c=str2num(s2);
			d=c-b;
			count++;
			cout<<c<<"-"<<b<<"="<<d<<endl;
		}
		cout<<"Ok!! "<<count<<" times"<<endl;
	}
	
	return 0;
	

}