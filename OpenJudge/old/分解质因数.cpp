#include <iostream>
using namespace std;

long long n;
int main()
{
	for(;;)
	{
		cin>>n;
		if(n<2)
		{
			cout<<"´íÎó"; 
		}
		else
		{	
			long long i=2;
			while(i<=n)
			{
				if(n%i==0)
				{
					do
					{
						cout<<i<<" ";
						n=n/i; 
					}
					while(n%i==0);
				}
				else
				{
					i=i+1;
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
