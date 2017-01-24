#include <iostream>
#include <math.h>
#include <vector>
#define LARGE 100 //Should be large enough
using namespace std;

int main()
{
	double nodes[16][3];
	for (int i=0;i!=16;++i)
	{
		cin>>nodes[i][0]>>nodes[i][1]>>nodes[i][2];
	}
	
	double input[LARGE][3];
	int j=0,n=0;
	cin>>input[0][0]>>input[0][1]>>input[0][2];
	++j;
	while (input[j-1][0]!=-1. && input[j-1][1]!=-1. && input[j-1][2] !=-1.)
	{
		cin>>input[j][0]>>input[j][1]>>input[j][2];
		++j;
	}
	n=j-1;
	double dist=1e20,dist1=1e20;
	vector<int> res(n,0);
	int num=0;
	for (int i=0;i!=n;++i)
	{
		dist=1e20;
		for (int k=0;k!=16;++k)
		{
			dist1=pow((input[i][0]-nodes[k][0]),2.)+pow((input[i][1]-nodes[k][1]),2.)+pow((input[i][2]-nodes[k][2]),2.);
			dist1=sqrt(dist1);
			if (dist1 < dist)
			{
				dist=dist1;
				res[i]=k;
			}
		}
		num=res[i];
		cout<<"("<<int(input[i][0])<<","<<int(input[i][1])<<","<<int(input[i][2])<<") maps to ("<<int(nodes[num][0])<<","<<int(nodes[num][1])<<","<<int(nodes[num][2])<<")"<<endl;
	}
	
	return 0;
}