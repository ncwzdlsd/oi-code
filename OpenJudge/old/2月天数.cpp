#include <iostream>
using namespace std; 

int main()
{
	int a,y;
		for(;;)
		{
			cin>>a;
			/*if(a%400==0||a%4==0&&a%100!=0)
				cout<<"2月天数="<<29;
			else
				cout<<"二月天数="<<28;*/
			/*y=(a%400==0||a%4==0&&a%100!=0)?29:28;
			cout<<y*/
			cout<<"二月天数="<<((a%400==0||a%4==0&&a%100!=0)?29:28);
		}
		return 0;
}
