#include <iostream>
using namespace std; 

int main()
{
	double a,b,c,x,y,z,t;
	
	for(;;)
	/*
	{
		cin>>a>>b>>c;
		
//		if(a==b||b==c||c==a)
//		{
//			cout<<"´íÎó"<<endl;
//			continue;
//		}
		
		if(a>b&&a>c)// if a is max
		{	
			x=a;
		
			if(b>c)
			{
				y=b;
				z=c;
			}
			else
			{
				y=c;
				z=b;
			}
			cout<<x<<">"<<y<<">"<<z<<endl;
		}		
		else if(c>b&&c>a)//if c is max	
		{
			x=c;
			
			if(b>a)
			{
				y=b;
				z=a;
			}
			else
			{
				y=a;
				z=b;
			}
			cout<<x<<">"<<y<<">"<<z<<endl;
		}
		else if(b>c&&b>a)//if b is max
		{
			x=b;
			
			if(c>a)
			{
				y=c;
				z=a;
			}
			else
			{
				y=a;
				z=c;
			}
			cout<<x<<">"<<y<<">"<<z<<endl;
		}		
		else
		{
			cout<<"´íÎó"<<endl;
			continue;
		}
	}
	*/
	{
	cin>>a>>b>>c;
	if(a==b||b==c||c==a)
	{
		cout<<"´íÎó"<<endl;
		continue;
	}
	if(a<b)
	{
		t=a;
		a=b;
		b=t;	
	}	
	if(a<c)
	{
		t=a;
		a=c;
		c=t;
	}
	if(b<c)
	{
		t=b;
		b=c;
		c=t;
	}
	cout<<a<<">"<<b<<">"<<c<<endl;
	}
	return 0;
}
