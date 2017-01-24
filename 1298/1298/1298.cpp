#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ss,s1,s2;
	while(getline(cin,s1) && s1!="ENDOFINPUT")
	{
		getline(cin,ss);
		getline(cin,s2);
		for(string::iterator iter = ss.begin(); iter != ss.end(); ++iter)
		{
			if(*iter >= 'F' && *iter <= 'Z')
			{
				*iter-=5;
			}
			else if(*iter >='A' && *iter<= 'E')
			{
				*iter+=21;
			}
		}
		cout<<ss<<endl;
	}

	return 0;
}
