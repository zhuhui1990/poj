#include <iostream>
#include <vector>

using namespace std;

int main(){
	int ncase;
	cin>>ncase;
	while(ncase){
		--ncase;
		int length;
		int n;
		cin>>length>>n;
		vector<int> loc(n);
		for(int i=0;i<n;++i){
			cin>>loc[i];
		}
		int minvalue = 0;
		int temp;
		for(int i=0;i<n;++i){
			int temp = loc[i] < length-loc[i]? loc[i]:length-loc[i];
			minvalue = temp > minvalue ? temp : minvalue;
		}
		int maxvalue = 0;
		for(int i=0;i<n;++i){
			int temp = loc[i] > length-loc[i]? loc[i]:length-loc[i];
			maxvalue = temp > maxvalue ? temp : maxvalue;
		}
		cout<<minvalue<<" "<<maxvalue<<endl;
	}
	return 0;
}