#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int compose(int n,int k){ //×éºÏÊý
	int result = 1;
	for(int i=0;i<k;++i){
		result *= (n-i);
	}
	for(int i=0;i<k;++i){
		result /= (i+1);
	}
	return result;
}

int getSum(const vector<int>& vec,const vector<int>& com){
	int res = 0;
	int n = vec.size();
	for(int i=0;i<n;++i){
		res += com[i]*vec[i];
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,sum;
	cin>>n>>sum;
	vector<int> vec;
	vector<int> com;
	for(int i=1;i<=n;++i){
		vec.push_back(i);
	}
	for(int i=0;i<n;++i){
		com.push_back(compose(n-1,i));
		//cout<<com[i]<<endl;
	}
	do{
		if(sum == getSum(vec,com)){
			cout<<vec[0];
			for(int i=1;i<n;++i){
				cout<<" "<<vec[i];
			}
			cout<<endl;
			return 0;
		}
	}while(next_permutation(vec.begin(),vec.end()));
	return 0;
}