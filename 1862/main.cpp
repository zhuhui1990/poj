//贪心
//取最大的两个碰撞即可
//简单证明：
// a,b,c三者相碰,最后大小为r
// r = 2*sqrt(2*sqrt(a*b)*c)
// r*r/8 = sqrt(a*b)*c
// (r*r/8)^2 = a*b*c*c
// 要使r最小，则c最小，说明必须让大的先碰
#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	double res = 1.;
	int n;
	cin>>n;
	double a,b,c;
	priority_queue<double> q;
	for(int i=0;i<n;++i){
		cin>>a;
		//cout<<"a="<<a<<endl;
		q.push(a);
	}
	while(q.size() > 1){
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		c = 2.*sqrt(a*b);
		q.push(c);
	}
	cout<<setprecision(3)<<fixed;
	cout<<q.top()<<endl;
	
	return 0;
}