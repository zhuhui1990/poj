#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

struct Node{
	char ss[32];
	int cnt;
	Node *lchild,*rchild;
};

Node *root;

void insertBST(Node*& root,char* s){
	if(root == NULL){
		Node *p = new Node;
		strcpy(p->ss,s);
		p->lchild = NULL;
		p->rchild = NULL;
		p->cnt = 1;
		root = p;
		return;
	}else{
		if(strcmp(s,root->ss) == 0){
			++(root->cnt);
			return;
		}else if(strcmp(s,root->ss) < 0){
			insertBST(root->lchild,s);
		}else{
			insertBST(root->rchild,s);
		}
	}
}

void midCalc(int n,Node* root){
	if(root == NULL){
		return;
	}
	midCalc(n,root->lchild);
	double d = double(root->cnt)/double(n)*100.;
	cout<<root->ss<<" "<<	d<<endl;
	midCalc(n,root->rchild);
}
int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	char s[32];
	int n=0;
	while(gets(s) != NULL){
		insertBST(root,s);
		++n;
	}
	midCalc(n,root);
	return 0;
}