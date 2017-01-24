#include <iostream>
#include <string>
#define N 105
using namespace std;

int main(){
	int n;
	string s;
	int pos1,pos2;
	int cnt[N],min;
	int res;
	while(cin>>n && n){
		min=25;
		res=0;
		getline(cin,s);
		for(int i=0;i<n;++i){
			getline(cin,s);
			cnt[i]=0;
			for(int j=0;j<s.length();++j){
				if(s[j]!='X') cnt[i]++;
			}
			if(cnt[i]<min) min=cnt[i];
		}

		for(int i=0;i<n;++i){
			res+=cnt[i]-min;
		}
		cout<<res<<endl;
	}
	return 0;
}