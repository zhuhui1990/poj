#include <iostream>
#include <cstdio>

using namespace std; 

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int a,b;
	while(cin>>a>>b){
		cout<<a % b<<endl;
	}
	return 0;
}