#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector<string> work;
	vector<string>::iterator it;


	work.push_back("http://www.acm.org/");
	it=work.begin();


	string operation;

	while (cin>>operation && operation !="QUIT"){
		if(operation == "VISIT"){
			while(work.end()!=it+1){
				work.pop_back();
			}

			string temp;
			
			getline(cin,temp);
			temp.erase(0,temp.find_first_not_of(" "));
			work.push_back(temp);
			it=work.end()-1;
			cout<<*it<<endl;
		}else if(operation == "FORWARD"){
			if(it <work.end()-1){
				it++;
				cout<<*it<<endl;
			}else {
				cout<<"Ignored"<<endl;
			}
		}else if(operation == "BACK"){
			if(it >work.begin()){
				it--;
				cout<<*it<<endl;
			}else {
				cout<<"Ignored"<<endl;
			}
		}


		
	
	}

	return 0;
}