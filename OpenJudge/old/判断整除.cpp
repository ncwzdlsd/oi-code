#include <iostream>
using namespace std; 

int main()
{
	int a; 
	
	for(;;)
	{
		cin>>a;
		if(a%3==0&&a%5==0)
			cout<<"��";
		else
			cout<<"����";	
	}
	return 0;
}
