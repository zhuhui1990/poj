#include <iostream>
#include <string>
#define N 105
using namespace std;

int isvowel(char a){
	int res=0;
	if (a=='a'){
		res=1;
	}else if(a=='e'){
		res=2;
	}else if(a=='i'){
		res=3;
	}else if(a=='o'){
		res=4;
	}else if(a=='u'){
		res=5;
	}
	return res;
}



int main(){
	string s;
	bool flag=true;
	int letter[N];
	while(cin>>s && s!="end"){
		flag=true;
		bool allcon=true;
		int l=s.length();
		for(int i=0;i<l;++i){
			letter[i]=isvowel(s[i]);
			//cout<<letter[i]<<endl;
		}
		//cout<<flag<<endl;
		//规则1
		for(int i=0;i<l;++i){
			if(letter[i]!=0) allcon=false;
		}
		if(allcon){
			flag=false;
		}
		//cout<<flag<<endl;
		//规则2
		for(int i=0;i<=l-3;i++){
			if(letter[i]==0 && letter[i+1]==0 && letter[i+2]==0){
				flag=false;
			}else if(letter[i]!=0 && letter[i+1]!=0 && letter[i+2]!=0){
				flag=false;
			}
		}
		//cout<<flag<<endl;
		//规则3
		for(int i=0;i<=l-2;i++){
			if(letter[i]!=2  && letter[i]!=4 && s[i+1]==s[i]){
				flag=false;
			}
		}
		//cout<<flag<<endl;
		if(flag){
			cout<<"<"<<s<<"> is acceptable."<<endl;
		}else{
			cout<<"<"<<s<<"> is not acceptable."<<endl;
		}
		
	}	
	
	return 0;
}
