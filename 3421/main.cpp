#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

typedef unsigned long long ull;

vector<int> prime_factor_time(int n){
	vector<int> res;
	for(int i=2;i*i<=n;++i){
		int time = 0;
		while(n%i == 0){
			++time;
			n/=i;
		}
		res.push_back(time);
	}
	if(n!=1){
		res.push_back(1);
	}
	return res;
}

ull factor(int n){
	ull res =1;
	for(int i=2;i<=n;++i){
		res *= i;
	}
	return res;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int x;
	while(cin>>x){
		vector<int> vec = prime_factor_time(x);
		int length = accumulate(vec.begin(),vec.end(),0);
		ull number = factor(length);
		for(int i=0;i<vec.size();++i){
			number /= factor(vec[i]);
		}
		cout<<length<<" "<<number<<endl;
	}
	return 0;
}