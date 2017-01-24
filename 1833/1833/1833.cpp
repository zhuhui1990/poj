#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int m,n,k;
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&n,&k);
		vector<int> s;
		for(int j=0;j<n;++j){
			int temp;
			scanf("%d",&temp);
			s.push_back(temp);
		}
		for(int j=0;j<k;++j){
			next_permutation(s.begin(),s.end());
		}
		for(int j=0;j<n;++j){
			printf("%d ",s[j]);
		}
		printf("\n");
	}


	return 0;
}