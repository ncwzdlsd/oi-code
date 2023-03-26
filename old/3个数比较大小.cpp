#include <iostream>
using namespace std; 

int main()
{	
	double a,b,c;
	for(;;)
	{
		cin>>a>>b>>c;
	/*	if(a>b)
		{
			if(a>c)
				cout<<a<<endl;
			else
				cout<<c<<endl;
		}
		else
		{
			if(b>c)
				cout<<b<<endl;
			else
				cout<<c<<endl;
		}
	}*/
		if((a>b)&&(a>c))cout<<a;
		if((b>a)&&(b>c))cout<<b;
		if((c>a)&&(c>b))cout<<c;
	}
	return 0;
}
