#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a,b,c,x1,x2,x;
	for(;;)
	{ 
	cin>>a>>b>>c;
		if(a==0)
		{
			if(b==0)
				{
				if(c==0)
					cout<<"任意实数"<<endl;
				else
					cout<<"错误"<<endl; 
				}
			else
				{
				x=-c/b;
				cout<<"x="<<x<<endl;
				}
		}
		else
		{
			if(b*b-4*a*c<0)
				{
					cout<<"无实数根";
				}
				else
				{
					x1=(-1*b+sqrt(b*b-4*a*c))/2*a;
					x2=(-1*b-sqrt(b*b-4*a*c))/2*a;
					cout<<"x1="<<(x1)<<endl;
					cout<<"x2="<<(x2)<<endl;
				}
		}
	}
	return 0;
}
