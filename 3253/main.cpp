#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
	long long n;
	while(cin>>n){
		priority_queue<long long,vector<long long>,greater<long long> > q;
		long long temp;
		for(long long i=0;i<n;++i){
			cin>>temp;
			q.push(temp);
		}
		long long res = 0;
		while(q.size() > 1){
			long long l1 = q.top();
			q.pop();
			long long l2 = q.top();
			q.pop();
			res += l1+l2;
			q.push(l1+l2);
		}
		cout<<res<<endl;
	}
	return 0;
}
