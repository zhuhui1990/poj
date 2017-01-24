#include <iostream>
//#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	int a[6];
	int n=0;
	int nn=0;
	int ncor=0;
	//ifstream f1("test.txt");
	//ifstream f2("ans.txt");
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5] && (a[0]||a[1]||a[2]||a[3]||a[4]||a[5])){
	// while(f1>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5] && (a[0]||a[1]||a[2]||a[3]||a[4]||a[5])){
		n=0;
		//f2>>ncor;
		
		n+=a[5];
		n+=a[4];
		if (a[4]>0){
			a[0]-=11*a[4];
			a[0]=max(a[0],0);
		}
		n+=a[3];
		if (a[3] >0){
			if(a[1]>=5*a[3]){
				a[1]-=5*a[3];
			}else{
				a[0]-=4*(5*a[3]-a[1]);
				a[0]=max(a[0],0);
				a[1]=0;
			}
		}
		//cout<<a[0]<<" "<<a[1]<<" "<<n<<endl;
		switch(a[2]%4){
		case(0):
			n+=a[2]/4;
			break;
		case(1):
			nn=(a[2]/4)+1;
			n+=nn;
			if(a[1]>=5){
				a[1]-=5;
			}else{
				a[0]-=4*(5-a[1]);
				a[0]=max(a[0],0);
				a[1]=0;
			}
			a[0]-=7;
			a[0]=max(a[0],0);
			break;
		case(2):
			nn=(a[2]/4)+1;
			n+=nn;
			if(a[1]>=3){
				a[1]-=3;
			}else{
				a[0]-=4*(3-a[1]);
				a[0]=max(a[0],0);
				a[1]=0;
			}
			a[0]-=6;
			a[0]=max(a[0],0);

			break;
		case(3):
			nn=(a[2]/4)+1;
			n+=nn;
			a[0]-=(a[1]==0?4:0);
			a[0]=max(a[0],0);
			a[1]-=1;
			a[1]=max(a[1],0);
			a[0]-=5;
			a[0]=max(a[0],0);
			break;
		}
		//cout<<a[0]<<" "<<a[1]<<" "<<n<<endl;
		if (a[1] >0){
			n+=(a[1]%9 == 0)?(a[1]/9):(a[1]/9+1);
			a[0]-=4*(9-((a[1]%9)?(a[1]%9):9));
			a[0]=max(a[0],0);
		}
		if (a[0] >0){
			n+=(a[0]%36 == 0)?(a[0]/36):(a[0]/36+1);
		}
		cout<<n<<endl;
	//	cout<<n<<" "<<ncor<<endl;
	//	system("pause");
	}
	return 0;
}