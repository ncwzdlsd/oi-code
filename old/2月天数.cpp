#include <iostream>
using namespace std; 

int main()
{
	int a,y;
		for(;;)
		{
			cin>>a;
			/*if(a%400==0||a%4==0&&a%100!=0)
				cout<<"2������="<<29;
			else
				cout<<"��������="<<28;*/
			/*y=(a%400==0||a%4==0&&a%100!=0)?29:28;
			cout<<y*/
			cout<<"��������="<<((a%400==0||a%4==0&&a%100!=0)?29:28);
		}
		return 0;
}
