#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<string> dict;
	string temp;
	string s0,s1;
	while(cin>>temp && temp!="XXXXXX"){
		dict.push_back(temp);
	}
	while(cin>>temp && temp!="XXXXXX"){
		bool flag=false;
		sort(temp.begin(),temp.end());
		s0=temp;

		for(int i=0;i<dict.size();++i){
				if(temp==dict[i]){
					cout<<temp<<endl;
					flag=true;
				}
		}
		next_permutation(temp.begin(),temp.end());
		
		while(temp!=s0){
			for(int i=0;i<dict.size();++i){
				if(temp==dict[i]){
					cout<<temp<<endl;
					flag=true;
				}
			}
			next_permutation(temp.begin(),temp.end());
		}
		if(!flag){
			cout<<"NOT A VALID WORD"<<endl;
		}
		cout<<"******"<<endl;
	}

	return 0;
}