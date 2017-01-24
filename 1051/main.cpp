#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 
string atom[30]={".-","-...","-.-.","-..",".","..-.","--.",
		 "....","..",".---","-.-",".-..","--","-.",
		 "---",".--.","--.-",".-.","...","-","..-",
		 "...-",".--","-..-","-.--","--..",
		 "..--",//underscore
		 ".-.-",//comma
		 "---.",//period
		 "----",//questionmark
		};

int latom[30];
vector<int> ss; 

int main(){
	for(int i=0;i<30;++i){
		latom[i]=atom[i].length();		
	}
	int n;
	cin>>n;
	string sin,smid,sout;
	for(int i=0;i<n;++i){
		cin>>sin;
		smid.clear();
		sout.clear();
		ss.clear();
		//step 1
		for(int j=0;j<sin.length();++j){
			int a;
			if(sin[j]<='Z' && sin[j]>='A'){
				a=sin[j]-'A';
			}else if(sin[j]=='_'){
				a=26;
			}else if(sin[j]==','){
				a=27;
			}else if(sin[j]=='.'){
				a=28;
			}else if(sin[j]=-'?'){
				a=29;
			}
		smid+=atom[a];
		ss.push_back(latom[a]);
		}
		//step 2
		reverse(ss.begin(),ss.end());		
		//step 3
		string stemp;
		string s3;
		int loc=0;
		int b;
		//cout<<ss.size()<<endl;
		for(int j=0;j<ss.size();++j){
			stemp=smid.substr(loc,ss[j]);
			loc+=ss[j];
			for(int k=0;k<30;++k){
				if(stemp==atom[k]){
					b=k;
					break;
				}
			}
			if(b<26){
				char temp='A'+b;
				sout.push_back(temp);
			}else if(b==26){
				sout.push_back('_');
			}else if(b==27){
				sout.push_back(',');

			}else if(b==28){
				sout.push_back('.');
			}else if(b==29){
				sout.push_back('?');
			}

			
	
		}



		cout<<i+1<<": "<<sout<<endl;	
	}
	return 0;

}
