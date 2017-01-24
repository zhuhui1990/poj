#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string strPost;

void getPost(const string& pre,const string& in){
	int iPos;
	if(pre == "" || in == ""){
		return;
	}
	iPos = in.find(pre[0]);
	getPost(pre.substr(1,iPos),in.substr(0,iPos));
	getPost(pre.substr(iPos+1),in.substr(iPos+1));
	strPost += pre[0];
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s1,s2;
	while(cin>>s1>>s2){
		strPost = "";
		getPost(s1,s2);
		cout<<strPost<<endl;
	}
	return 0;
}