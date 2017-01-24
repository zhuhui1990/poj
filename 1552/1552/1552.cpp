#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> a(16);
	while (cin>>a[0] && a[0] !=-1){
		int res=0;
		int i=1;
		while (cin>>a[i] && a[i] !=0){
			i++;
		}
		for (int j=0;j!=i;j++){
			for (int k=0;k!=i;k++){
				if(a[j]*2==a[k]){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}

	return 0;
}