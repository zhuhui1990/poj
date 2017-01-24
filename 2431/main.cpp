#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e5+5;
struct Station{
	int loc;
	int fuel;
};

bool operator < (const Station& lhs,const Station& rhs){
		return lhs.loc < rhs.loc;
	}

Station stat[maxn];


int main(){
	int n;
	//while(cin>>n){
	cin>>n;
		for(int i=0;i<n;++i){
			cin>>stat[i].loc>>stat[i].fuel;
		}
		int l,p;
		cin>>l>>p;
		
		for(int i=0;i<n;++i){
			stat[i].loc = l - stat[i].loc;
			//cout<<"i="<<i<<" loc[i]="<<loc[i]<<endl;
		}
		stat[n].loc = l;
		stat[n].fuel = 0;
		++n;
		sort(stat,stat+n);
		//loc[n] = l;
		priority_queue<int> q;
		int pos=0,res=0,tank=p;
		//bool flag=true;
		for(int i=0;i<n;++i){
			int d = stat[i].loc-pos;
			while(tank - d < 0){
				if(q.empty()){
					puts("-1");
					return 0;
					//flag=false;
					//break;
				}
				tank += q.top();
				q.pop();
				++res;
			}
			//if(!flag)
			//	break;
			tank -= d;
			pos = stat[i].loc;
			q.push(stat[i].fuel);
			//cout<<"i="<<i<<" pos="<<pos<<" q.size()="<<q.size()<<endl;
		}
		//if(!flag)
		//	continue;
		cout<<res<<endl;
	//}
	return 0;
}