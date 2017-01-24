#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,s1;
	while(getline(cin,s) && s!="#"){
		int l=s.length();
		s1="";
		for(int i=0;i<l;++i){
			if(s[i]==' '){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('0');
			}else if(s[i]=='!'){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('1');
			}else if(s[i]=='$'){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('4');
			}else if(s[i]=='%'){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('5');
			}else if(s[i]=='('){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('8');
			}else if(s[i]==')'){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('9');
			}else if(s[i]=='*'){
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('a');
			}else{
				s1.push_back(s[i]);
			}
		}
		cout<<s1<<endl;
	}
	return 0;
}
