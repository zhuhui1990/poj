#include <iostream>
#include <string>

using namespace std;

int main(){
	string sin="";
	string sout="";
	while(getline(cin,sin)){
		string::iterator   it;
		for (it=sin.begin();it!=sin.end();++it){
			switch(*it){
			case('B'):
			case('F'):
			case('P'):
			case('V'):
				sout.push_back('1');
				break;
			case('C'):
			case('G'):
			case('J'):
			case('K'):
			case('Q'):
			case('S'):
			case('X'):
			case('Z'):
				sout.push_back('2');
				break;
			case('D'):
			case('T'):
				sout.push_back('3');
				break;
			case('L'):
				sout.push_back('4');
				break;
			case('M'):
			case('N'):
				sout.push_back('5');
				break;
			case('R'):
				sout.push_back('6');
				break;
			default:
				sout.push_back('7');
				break;
			}
		}
		

		string sout1;
		if(sout.begin()!=sout.end()){
			if (sout[0]!='7'){
				sout1.push_back(sout[0]);
			}
			for (it=sout.begin()+1;it!=sout.end();++it){
				if(*it!=*(it-1) && *it!='7'){
					sout1.push_back(*it);
				}
			}
		}
		cout<<sout1<<endl;
		sin.clear();
		sout.clear();
		sout1.clear();
	}
	return 0;
}