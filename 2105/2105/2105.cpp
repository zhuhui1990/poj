#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	int n=0;
	cin>>n;
	for (int i=0;i!=n;++i)
	{
		string along;
		cin>>along;
		string a1(8,'0'),a2(8,'0'),a3(8,'0'),a4(8,'0');
		for(int j=0;j!=8;++j)
		{
			a1[j]=along[j];
			a2[j]=along[8+j];
			a3[j]=along[16+j];
			a4[j]=along[24+j];
		}
		bitset<8> b1(a1),b2(a2),b3(a3),b4(a4);
		cout<<b1.to_ulong()<<"."<<b2.to_ulong()<<"."<<b3.to_ulong()<<"."<<b4.to_ulong()<<endl;
	}

	return 0;
}