#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int n;
	while (cin>>n){
		vector<int> a;
		vector<bool> jolly(n-1,false);
		int n1;
		for (int i=0;i!=n;++i){
			cin>>n1;
			a.push_back(n1);
		}
		int dif;
		for (int i=1;i!=n;++i){
			dif=abs(a[i]-a[i-1]);
			if(dif>=1 && dif <= n-1){
				jolly[dif-1]=true;
			}
		}

		bool res=true;
		for (int i=0;i!=n-1;++i){
			if(!jolly[i]){
				res=false;
			}
		}
		if(res){
			cout<<"Jolly"<<endl;
		}else{
			cout<<"Not jolly"<<endl;
		}
		a.clear();
		jolly.clear();
	}

	return 0;
}