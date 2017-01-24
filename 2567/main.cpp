#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 1024;
istringstream iss;

void parse(vector<set<int> >& adj,int p){
	int x;
	iss>>x;
	//cout<<"x="<<x<<endl;
	if(p!=0){
		adj[p].insert(x);
		adj[x].insert(p);
	}
	while(true){
		char ch;
		iss>>ch;
		if(ch == ')'){
			break;
		}else if(ch == '('){
			parse(adj,x);
		}
	}
	return;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
  char c;
	string s;
	while(getline(cin,s)){
		//cout<<"s="<<s<<endl;
		iss.str(s);
		iss>>c;
		vector<set<int> > adj(maxn);
		parse(adj,0);
		priority_queue<int,vector<int>,greater<int> > leafs;
		int n=0;
		for(int i=0;i<adj.size();++i){
			if(adj[i].size()){
				++n;
				if(adj[i].size() == 1){
					leafs.push(i);
				}
			}
		}
		for(int k=1;k<n;++k){
			int x = leafs.top();
			leafs.pop();
			int p = *(adj[x].begin());
			if(k>1){
				printf(" ");
			}
			printf("%d",p);
			adj[p].erase(x);
			if(adj[p].size() == 1){
				leafs.push(p);
			}
		}
		printf("\n");
	}
	return 0;
}