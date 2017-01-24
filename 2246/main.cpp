#include <stack>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

struct Node{
	int row,col;
};

map<char,Node> matrix;


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	char name;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>name;
		cin>>matrix[name].row>>matrix[name].col;
	} 
	string exp;
	while(cin>>exp){
		int count = 0;
		stack<Node> array;
		int i=0;
		for(;i<exp.size();++i){
			if(exp[i] == '('){
				continue;
			}else if(exp[i] == ')'){
				Node b = array.top();
				array.pop();
				Node a = array.top();
				array.pop();
				if(a.col != b.row){
					cout<<"error"<<endl;
					break;
				}
				count += a.row*b.row*b.col;
				Node tmp = {a.row,b.col};
				array.push(tmp);
			}else{
				array.push(matrix[exp[i]]);
			}
		}
		if(i == exp.size()){
			cout<<count<<endl;
		}
	}
	return 0;
}
