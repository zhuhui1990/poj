//BFS
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 9999;
bool visited[maxn];
int cnt[maxn];
bool prime[maxn];


bool isprime(int a){
	for(int i=2;i*i<=a;++i){
		if(a%i == 0){
			return false;
		}
	}
	return true;
}

//4位数质数打表
void primetable(){
	memset(prime,false,sizeof(prime));
	for(int i=1000;i<=9999;++i){
		if(isprime(i)){
			prime[i] = true;
		}
	}
}


int bfs(int a,int b){
	memset(cnt,0,sizeof(cnt));
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(a);
	visited[a] = true;
	int t[4];
	while(!q.empty()){
		int c = q.front();
		//cout<<"c="<<c<<endl;
		q.pop();
		if(c == b){
			return cnt[c];
		}
		t[0] = c/1000;
		t[1] = c%1000/100;
		t[2] = c%100/10;
		t[3] = c%10;
		//依次改变a的一位，是未访问的质数就入队
		int temp;
		for(int i=0;i<4;++i){
			temp = t[i];
			int start = i==0? 1:0;
			for(int j=start;j<10;++j){
				if(j!=temp){
					t[i] = j;
					int vtemp=t[0]*1000+t[1]*100+t[2]*10+t[3];
					if(prime[vtemp] && !visited[vtemp]){
						visited[vtemp] = true;
						cnt[vtemp] = cnt[c]+1;
						q.push(vtemp);
					}
				} 
			}
			t[i] = temp;
		}
	}
	return -1;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase;
	cin>>kase;
	int a,b;
	primetable();
	while(kase--){
		cin>>a>>b;
		int res = bfs(a,b);
		if(res < 0){
			cout<<"Impossible"<<endl;
		}else{
			cout<<res<<endl;
		}
	}
	return 0;
}