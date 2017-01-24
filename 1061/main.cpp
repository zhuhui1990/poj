#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a,long long b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

void exeuclid(long long a,long long b,long long& x,long long& y){
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}
	exeuclid(b,a%b,x,y);
	long long t = x;
	x = y;
	y = t-a/b*y;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
  long long x,y,m,n,l;
  cin>>x>>y>>m>>n>>l;
  long long a = n-m, b = l, c = x-y;
  long long r = gcd(a,b);
  if(c%r != 0){
  	cout<<"Impossible"<<endl;
  	return 0;
  }
  a /= r;
  b /= r;
  c /= r;
  long long j1,j2;
  exeuclid(a,b,j1,j2);
  long long t = c*j1/b;
  j1 = c*j1-t*b;
  if(j1<0){
  	if(b>0) j1 += b;
  }
  cout<<j1<<endl;
	return 0;
}