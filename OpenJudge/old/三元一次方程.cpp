#include <bits/stdc++.h>
using namespace std;

int m,n;
bool flag;

int main()
{
	for(;;)
	{
		flag=false;
		cin>>n>>m;
		if(n<5*m)
			cout<<"´íÎó£ºÊäÈë´íÎó"<<endl;
		else
		{
			for(int a=1;a<=m;a=a+1)
			{
//				if(flag)
//				{
//					break;
//				}
				for(int b=1;b<=m;b=b+1)
				{
//					if(flag)
//					{
//						break;
//					}
					for(int c=1;c<=m;c=c+1)
					{
						if(15*a+10*b+5*c==n&&a+b+c==m)
						{
							cout<<a<<" "<<b<<" "<<c<<endl;
							flag = true;
						}							
//						else
//						{
//							cout<<"´íÎó2"<<endl;
//							flag=true;
//							break;
//						}
					} 
				}
			}
			
			if(!flag)
			{
				cout<<"´íÎó:ÎÞÕûÊý½â"<<endl; 
			}
			
		} 
	}
	return 0;
} 
