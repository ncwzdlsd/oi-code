#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
	double a,b,c,x1,x2;
	cout<<"����һԪ���η��̵�a��b��c"<<endl;
	for(;;)
		{
			cin>>a>>b>>c;
			if(a==0)
			{
				cout<<"����";
			}
			else
			{
				if(b*b-4*a*c<0)
				{
					cout<<"��ʵ����";
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
