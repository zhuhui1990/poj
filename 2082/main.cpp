#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Rect{
	int w,h;
};

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n,ans,i,lasth,totalw,curarea;
	Rect data;
	while(scanf("%d",&n) && n != -1){
		ans = 0;
		stack<Rect> s;
		lasth = 0;
		for(int i=0;i<n;++i){
			scanf("%d %d",&data.w,&data.h);
			if(data.h > lasth){
				s.push(data);
			}else{
				totalw = 0;
				curarea = 0;
				while(!s.empty() && s.top().h > data.h){
					totalw += s.top().w;
					curarea = totalw * s.top().h;
					if(curarea > ans){
						ans = curarea;
					}
					s.pop();
				}
				totalw += data.w;
				data.w = totalw;
				s.push(data);
			}
			lasth = data.h;
		}
		totalw = 0;
		curarea = 0;
		while(!s.empty()){
			totalw += s.top().w;
			curarea = totalw * s.top().h;
			if(curarea > ans){
				ans = curarea;
			}
			s.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}