#include <iostream>
#include <string>
#include <algorithm>
#define N 20

using namespace std;

int main(){
	int n;
	string s;
	int l1;
	int a[N];
	bool flag=false;
	while(cin>>n>>s && n!=0 ){
		//cout<<n<<endl;
		flag=false;
		sort(s.begin(),s.end());
		l1=s.length();
		for(int i=0;i<l1;i++){
			a[i]=s[i]-'A'+1;
			//cout<<s[i]<<" "<<a[i]<<endl;
		}
		for(int i=l1-1;i>=0;i--){
			for(int j=l1-1;j>=0;j--){
				if (j==i) continue;
				for(int k=l1-1;k>=0;k--){
					if(k==i || k==j) continue;
					for(int l=l1-1;l>=0;l--){
						if( l==i || l==j || l==k) continue;
						for(int m=l1-1;m>=0;m--){
							if(m==i || m==j || m==k || m==l) continue;
							if(a[i]-a[j]*a[j]+a[k]*a[k]*a[k]-a[l]*a[l]*a[l]*a[l]+a[m]*a[m]*a[m]*a[m]*a[m] == n){
								cout<<s[i]<<s[j]<<s[k]<<s[l]<<s[m]<<endl;
								flag=true;
							}
							if(flag) break;
						}
						if(flag) break;
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) break;
		}
		
		if(!flag){
			cout<<"no solution"<<endl;
		}
	}
	return 0; 
}