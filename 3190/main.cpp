#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 50005;

struct Cow{
	int index;
	int start;
	int end;
	bool operator < (const Cow& rhs) const{ //必须声明this是const
		return start < rhs.start;
	}
};

struct Stall{
	int id;
	int end;
	bool operator < (const Stall& rhs) const{
		return end > rhs.end;
	}
};

Cow cow[maxn];
int result[maxn];

priority_queue<Stall> q;

void put_cow(int i,bool new_stall){
	Stall s;
	if(new_stall){
		s.id = q.size()+1;
	}else{ //只拿走一个cow，这样最后q.size()即为最大N
		s.id = q.top().id;
		q.pop();
	}
	s.end = cow[i].end;
	result[cow[i].index] = s.id;
	q.push(s);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		cow[i].index = i;
		scanf("%d %d",&(cow[i].start),&(cow[i].end));
	}	
	sort(cow,cow+n);
	put_cow(0,true);
	for(int i=1;i<n;++i){
		put_cow(i,cow[i].start <= q.top().end);
	}
	printf("%d\n",q.size());
	for(int i=0;i<n;++i){
		printf("%d\n",result[i]);
	}
	return 0;
}