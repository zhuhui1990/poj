//贪心+优先队列
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 2505;

pair<int,int> cow[maxn];
pair<int,int> bottle[maxn];
priority_queue<int,vector<int>,greater<int> > q;


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int c,l;
	cin>>c>>l;
	for(int i=0;i<c;++i){
		cin>>cow[i].first>>cow[i].second;
	}
	for(int i=0;i<l;++i){
		cin>>bottle[i].first>>bottle[i].second;
	}
	sort(cow,cow+c);
	sort(bottle,bottle+l);
	int cur = 0;
	int result = 0;
	for(int i=0;i<l;++i){
		while(cur < c && cow[cur].first <= bottle[i].first){
			q.push(cow[cur].second);
			++cur;
		}
		while(!q.empty() && bottle[i].second){
			int maxspf = q.top();
			q.pop();
			if(maxspf >= bottle[i].first){
				++result;
				--bottle[i].second;
			}
		}
	}
	cout<<result<<endl;
	return 0;
}
