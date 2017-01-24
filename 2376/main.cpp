#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 25005;

struct Node{
	int start,end;
};

bool comp(const Node& lhs, const Node& rhs){
	return lhs.start < rhs.start;
}

Node node[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;++i){
		scanf("%d %d",&(node[i].start),&(node[i].end));
	}
	sort(node,node+n,comp);
	if(node[0].start > 1){
		printf("-1\n");
		return 0;
	}
	int time = node[0].end;
	int res = 1,id = 0;
	for(int i=0;i<n;){
		int maxloc = 0;
		for(int j=i+1;j<n;++j){
			if(node[j].start > node[id].end+1){
				break;
			}
			if(node[j].start >= node[id].start && node[j].end >= node[id].end+1){ //忽略比当前结束还早的任务
				if(node[j].end > node[maxloc].end){
					maxloc = j;
				}
			}
		}
		if(maxloc == 0){
			++i;
		}else{
			++res;
			id = maxloc;
			i = id;
		}
	}
	if(node[id].end >= t){
		printf("%d\n",res);
	}else{
		printf("-1\n");
	}
		
	return 0;
}