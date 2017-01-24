#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> s;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	while(kase--){
		int n;
		cin>>n;
		int p;
		int t = 0;
		for(int i=0;i<n;++i){
			cin>>p;
			for(int j = 0;j<p-t;++j){
				s.push(-1);
			}
			if(s.top() == -1){
				if(i!=0){
					cout<<" ";
				}
				cout<<"1";
				s.pop();
				s.push(1);
			}else{
				int itop = s.top();
				s.pop();
				while(s.top()!=-1){
					itop += s.top();
					s.pop();
				}
				cout<<" "<<itop+1;
				s.pop();
				s.push(itop+1);
			}
			t = p;
		}
		cout<<endl;
		while(!s.empty()){
			s.pop();
		}
	}
	return 0;
}