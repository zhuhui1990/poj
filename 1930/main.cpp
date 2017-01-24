#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <limits>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a,ull b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}

ull ten_pow(int x){
	ull result = 1;
	for(int i=0;i<x;++i){
		result *= 10;
	}
	return result;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string line;
	while(cin>>line){
		if(line == "0"){
			break;
		}
		string digit = line.substr(2,line.length()-5);
		size_t length = digit.length();
		const ull n = atoi(digit.c_str());
		if(n==0){
			cout<<"0/1"<<endl;
			continue;
		}
		ull minx = numeric_limits<ull>::max();
		ull miny = 0;
		for(int i=1;i<=length;++i){
			string first = digit.substr(0,length-i);
			ull x = ten_pow(length) - ten_pow(length-i);
			ull y = n - atoi(first.c_str());
			ull d = gcd(x,y);
			x /= d;
			y /= d;
			if(minx > x){
				minx = x;
				miny = y;
			}
		}
		cout<<miny<<"/"<<minx<<endl;
	}
	return 0;
}