#include <iostream>

using namespace std;

const int maxn = 2005;
char input[maxn];
char output[maxn];


int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;++i){
			cin>>input[i];
		}
		int a = 0,b = n - 1;
		int loc = 0;
		while(a <= b){
			bool left = false;
			for(int i=0;i+a<=b;++i){
				if(input[a+i] < input[b-i]){
					left = true;
					break;
				}
				else if(input[a+i] > input[b-i]){
					left = false;
					break;
				}
			}
			if(left){
				output[loc] = input[a];
				++a;
			}else{
				output[loc] = input[b];
				--b;
			}
			++loc;
		}
		int row = 0;
		while(n > 0){
			for(int i=0;i< 80 && i < n;++i){
				cout<<output[row*80+i];
			}
			cout<<endl;
			n -= 80;
			++row;
		}
	}
	return 0;
}