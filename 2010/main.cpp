#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100016;
const int inf = 0x3f3f3f3f;


pair<int,int> cow[maxn];
int lower[maxn],upper[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,c,f;
	cin>>n>>c>>f;
	int half = n/2;
	for(int i=0;i<c;++i){
		cin>>cow[i].first>>cow[i].second;
	}
	sort(cow,cow+c);
	{
		int total = 0;
		priority_queue<int> q;
		for(int i=0;i<c;++i){
			lower[i] = q.size() == half? total : inf;
			q.push(cow[i].second);
			total += cow[i].second;
			if(q.size() > half){
				total -= q.top();
				q.pop();
			}
		}
	}
	{
		int total = 0;
		priority_queue<int> q;
		for(int i=c-1;i>=0;--i){
			upper[i] = q.size() == half? total : inf;
			q.push(cow[i].second);
			total += cow[i].second;
			if(q.size() > half){
				total -= q.top();
				q.pop();
			}
		}
	}
	int result;
	bool flag = false;
	for(int i=c-1;i>=0;--i){
		if(lower[i] + cow[i].second + upper[i] <= f){
			result = cow[i].first;
			flag = true;
			break;
		}
	}
	if(flag){
		cout<<result<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	return 0;
}