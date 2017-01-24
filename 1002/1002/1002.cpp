#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>>n;

	char mapping[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','+','7','7','8','8','8','9','9','9','+'};

	string *in;
	vector<string> out;
	in = new string[n];


	for (int i=0;i<n;++i){
		cin>>in[i];
		out.push_back("");
		
		int length=in[i].length();
	//	int cnt=0;
		for (int j=0;j<length;++j){
			char x=in[i][j];
			//cout<<x<<endl;
			if(x<='9' && x >= '0' ){
				out[i].push_back(x);
			}else if(x<='Z' && x>='A'){
				char y=mapping[x-'A'];
				if(mapping[y]!='+'){
					out[i].push_back(y);
				}
			}
		}
	    out[i].insert(3,"-");
		//cout<<out[i].length()<<endl;
		//cout<<out[i]<<endl;
	}

	
	sort(out.begin(),out.end());
	out.push_back("zzzzzzz");
	//output
	bool duplicate;
	for(int i=0;i<n-1;++i){
		int num=1;
		while(out[i]==out[i+1]){
			num++;
			i++;
		}
	
		if(num>1){
			duplicate=true;
			cout<<out[i]<<" "<<num<<endl;
		}
	
	}

	if(!duplicate){
		cout<<"No duplicates."<<endl;
	}


	//system("pause");
	delete [] in;
	return 0;
}