#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int array[maxn];

int main(){
	int r,n;
	while(cin>>r>>n && (r !=-1 || n != -1)){
		for(int i=0;i<n;++i){
			cin>>array[i];
		}
		sort(array,array+n);
		int cnt = 0, i = 0;
		int s;
		while(i<n){
			s = array[i];
			++i;
			while(i<n && array[i] <= s+r){
				++i;
			}
			int p = array[i-1];
			while(i<n && array[i] <= p+r){
				++i;
			}
			++cnt;
		}
		cout<<cnt<<endl;
		
	}
	return 0;
}