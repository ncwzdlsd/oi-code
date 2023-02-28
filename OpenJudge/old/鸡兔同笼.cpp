#include <iostream>
using namespace std; 

int main()
{
	int a,b,x,y;
	double x1,y1;

	for(;;)
	{
		cin>>a>>b;
		x=(4*a-b)/2;
		y=(b-2*a)/2;
		x1=((4*a-b)/(double)(2));
		y1=((b-2*a)/(double)2);
		//x1=(4*a-b)/2.0;
		//y1=(b-2*a)/2.0;
		
		if(x<0||y<0||x1-x!=0||y1-y!=0)
		{
			cout<<"无解"<<endl;
		
		}	
		else
		{
			cout<<"鸡数="<<x<<endl;
			cout<<"兔数="<<y<<endl;
		}
	}
	return 0;
}
