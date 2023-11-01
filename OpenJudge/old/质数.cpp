#include <iostream>
using namespace std;

int n;
int main()
{
	int i,j,c;
	
	for(;;)
	{
		cin>>n;
		if(n<=1)
			cout<<"´íÎó"<<endl;
		else
		{
			c = 0;
			
			for(i=2;i<=n;i=i+1)
			{
				for(j=2;i%j!=0 && j<=i;j=j+1)
				{
				}
				if(j==i)
				{
					cout<<j<<" ";
					c=c+1;
					if(c==5)
					{
						c=0;
						cout<<endl;
					}
				}									
			}
			cout<<endl;
		}		
	}
}
