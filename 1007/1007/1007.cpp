#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
	int length=0,n=0;
	cin>>length>>n;
	vector<string> DNAs;
	vector<int> unsortedness;
	string temp;
	for(int i=0;i<n;++i){
		cin>>temp;
		DNAs.push_back(temp);
		unsortedness.push_back(0);
		for(int j=0;j<length;++j){
			char a=temp[j];
			for(int k=j+1;k<length;++k){
				char b=temp[k];
				if(a>b){
					unsortedness[i]++;
				}
			}
		}
		//cout<<unsortedness[i]<<endl;
	}
	//cout<<endl;
	int temp0=0;
	for(int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			if(unsortedness[i]>unsortedness[j]){
				temp=DNAs[i];
				DNAs[i]=DNAs[j];
				DNAs[j]=temp;
				temp0=unsortedness[i];
				unsortedness[i]=unsortedness[j];
				unsortedness[j]=temp0;
			}
		}
		cout<<DNAs[i]<<endl;
	}
	//system("pause");
	return 0;
}