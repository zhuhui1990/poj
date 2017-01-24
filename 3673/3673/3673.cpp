#include <iostream>
#include <vector>

using namespace std;

int main(){

	int A,B;
	cin>>A>>B;
	vector<int> a,b;

	while(A>0){
		a.push_back(A%10);
		A /=10; 
	}

	while(B>0){
		b.push_back(B%10);
		B /=10;
	}

	unsigned int sizea=a.size();
	unsigned int sizeb=b.size();

	int res=0;
	for(unsigned int i=0;i<sizea;++i){
		for(unsigned int j=0;j<sizeb;++j){
			res+=a[i]*b[j];
		}
	}

	cout<<res<<endl;

	return 0;
}