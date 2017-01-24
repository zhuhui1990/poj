#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> x;
	for(int i=0;i<n;++i){
		int x0;
		cin>>x0;
		x.push_back(x0);
	}
	sort(x.begin(),x.end());
	
	int pos=(n-1)/2;
	cout<<x[pos]<<endl;

	return 0;
}