#include<iostream>

using namespace std;

int main(){
	int p=0,e=0,i=0,d=0;
	int num=0;
	int destination=0;
	while(cin>>p>>e>>i>>d && p!=-1 && e!=-1 && i!=-1 && d!=-1){
		num++;
		for(destination=d;destination<21252;++destination){
			if((destination-p)%23==0){
				break;
			}
		}
		for(;destination<21252;destination+=23){
			if((destination-e)%28==0){
				break;
			}
		}
		for(;destination<21252;destination+=23*28){
			if((destination-i)%33==0){
				break;
			}
		}
		if(destination==0){
			destination=21252;
		}
		cout<<"Case "<<num<<": the next triple peak occurs in "<<destination-d<<" days."<<endl;
	}
	return 0;
}