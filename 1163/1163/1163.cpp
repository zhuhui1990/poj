#include <iostream>

using namespace std;
int main(){
	int n;
	cin>>n;
	int **input;
	input = new int*[n];
	input[0]=new int[n*n];
	for (int i=0;i<n-1;++i){
		input[i+1]=input[i]+n;
	}

	for (int i=0;i<n;++i){
		for (int j=0;j<i+1;++j){
			cin>>input[i][j];
		}
	}

	for (int i=n-2;i>=0;--i){
		for(int j=0;j<i+1;++j){
			input[i][j] += max(input[i+1][j],input[i+1][j+1]);
		}
	}

	cout<<input[0][0]<<endl;

	delete [] input[0];
	delete [] input;
	return 0;
}