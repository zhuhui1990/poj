#include <iostream>
#include <string>
#define N 1000
using namespace std;

int main(){
	int n;
	string s;
	char in[N];
  char left[N];
	int count;
	bool full=false;
	while(cin>>n && n){
		cin>>s;
		count=0;
		int l=s.length();
		for(int j=0;j<n;++j){
			in[j]='0';
		}
		for(int i=0;i<l;++i){
			left[i]='0';
		}
		
		
		for(int i=0;i<l;++i){
			bool flag=false;
			//����Ƿ�����ס
			for(int j=0;j<n;++j){
				if(in[j]==s[i]){
					in[j]='0'; //���ĳ����
					flag=true;
				}
			}
			//����Ƿ����뿪
			for(int k=0;k<count;++k){
				if(left[k]==s[i]){
					flag=true;
				}
			}
			
			if(flag) continue;
				
			full=true;
			//����Ƿ��пշ���
			for(int j=0;j<n;++j){
				if(in[j]=='0'){
					full=false;
					break;
				}
			}
			//���Ž�ĳ������
			if(!full){
				for(int j=0;j<n;++j){
					if(in[j]=='0'){
						in[j]=s[i];
						break;
					}
				}
			}else{
				left[count]=s[i];
				count++;
			}
			//cout<<"i="<<i<<endl;
			//for(int j=0;j<n;++j){
			//	cout<<in[j]<<" ";
			//}
			//cout<<endl;
			
		}
		
	
		
		if(count){
			cout<<count<<" customer(s) walked away."<<endl;
		}else{
			cout<<"All customers tanned successfully."<<endl;
		}
	}
	return 0;
}