#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	map<int,int> q;
	int c;
	int k,p;
	map<int,int>::iterator it;
	while(scanf("%d",&c) && c != 0){
		if(c == 1){
			cin>>k>>p;
			q[p] = k;
		}else if(c == 3){
			if(q.empty()){
				//cout<<0<<endl;
				printf("0\n");
			}else{
				//cout<<q.begin()->first<<endl;
				printf("%d\n",q.begin()->second);
				q.erase(q.begin());
			}
		}else if(c == 2){
			if(q.empty()){
				//cout<<0<<endl;
				printf("0\n");
			}else{
				it = q.end();
				--it;
				//cout<<it->first<<endl;
				printf("%d\n",it ->second);
				q.erase(it);
			}
		}
	}
	return 0;
}