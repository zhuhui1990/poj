#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int maxlen = 13;


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	char s1[maxlen],s2[maxlen];
	char str[maxlen*2+1];
	map<string,string> ht;
	while(gets(str)){
		if(strlen(str) == 0){
			break;
		}
		sscanf(str,"%s %s",s1,s2);
		ht[s2] = s1;
	}
	string ss,p_out;
	while(cin>>ss){
		if(ht.find(ss) == ht.end()){
			cout<<"eh"<<endl;
		}else{
			cout<<ht[ss]<<endl;
		}
	}
	
	return 0;
}