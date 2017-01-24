#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct Dat{
	int id;
	int time;
	int period;
	bool operator < (const Dat& rhs) const{
		if(time != rhs.time){
			return time > rhs.time;
		}else{
			return id > rhs.id;
		}
	}
};



int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	Dat dat;
	priority_queue<Dat> q;
	string s;
	while(cin>>s && s !="#"){
		cin>>dat.id>>dat.period;
		dat.time = dat.period;
		q.push(dat);
	}
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		dat = q.top();
		q.pop();
		cout<<dat.id<<endl;
		dat.time += dat.period;
		q.push(dat);
	}

	return 0;
}