#include <iostream>
#include <string>
using namespace std;

string month_in_[19]=
	{"pop", "no", "zip", "zotz", "tzec",
	 "xul", "yoxkin", "mol", "chen", "yax", 
	 "zac", "ceh", "mac", "kankin", "muan",
	 "pax", "koyab", "cumhu", "uayet"};

string month_out_[20]=
	{"imix", "ik", "akbal", "kan", "chicchan",
	 "cimi", "manik", "lamat", "muluk", "ok",
	 "chuen", "eb", "ben", "ix", "mem",
	 "cib", "caban", "eznab", "canac", "ahau"
	};

int month_in_convert(string month_in_1){
	for(int i=0;i<19;++i){
		if(month_in_1 == month_in_[i]){
			return i;
		}
	}
}

string month_out_convert(int month_out){
	return month_out_[month_out];
}

int main(){
	int n=0;
	cin>>n;
	cout<<n<<endl;
	int day_in=0,month_in=0,year_in=0;
	int day_out=0,month_out=0,year_out=0;
	int day_of_year_out=0;
	string temp;
	string month_in_1;
	string month_out_1;
	for(int i=0;i<n;++i){
		int dayfromstart=0;
		cin>>day_in>>temp>>month_in_1>>year_in;
		month_in=month_in_convert(month_in_1);
		dayfromstart+=year_in*365;
		dayfromstart+=month_in*20;
		dayfromstart+=day_in;
		year_out=dayfromstart/260;
		day_of_year_out=dayfromstart%260;
		day_out=(day_of_year_out%13)+1;
		month_out=day_of_year_out%20;
		month_out_1=month_out_convert(month_out);
		cout<<day_out<<" "<<month_out_1<<" "<<year_out<<endl;
	}
	
	return 0;
}