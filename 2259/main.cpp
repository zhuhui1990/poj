#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

int kase;
int nteam;
const int maxt = 1005;
const int maxn = 1000005;
queue<long> q[maxt];
queue<int> s;
int elem2team[maxn];
bool flag[maxt];

void init(){
	for(int i=0;i<nteam;++i){
		flag[i] = false;
		while(!q[i].empty()){
			q[i].pop();
		}
	}
	while(!s.empty()){
		s.pop();
	}
}

void input(){
	long elem;
	int nelem;
	for(int i=0;i<nteam;++i){
		cin>>nelem;
		for(int j=0;j<nelem;++j){
			cin>>elem;
			elem2team[elem] = i;
		}
	}
}

void solve(){
	string ss;
	long elem;
	cout<<"Scenario #"<<++kase<<endl;
	while(cin>>ss && ss!="STOP"){
		if(ss == "ENQUEUE"){
			cin>>elem;
			if(!flag[elem2team[elem]]){
				flag[elem2team[elem]] = true;
				s.push(elem2team[elem]);
			}
			q[elem2team[elem]].push(elem);
		}else if(ss == "DEQUEUE"){
			int team = s.front();
			cout<<q[team].front()<<endl;
			q[team].pop();
			if(q[team].empty()){
				s.pop();
				flag[team] = false;
			}
		}
	}
	cout<<endl;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	kase = 0;
	while(cin>>nteam && nteam){
		init();
		input();
		solve();
	}
	
	return 0;
}