#include <iostream>
using namespace std;

int main()
{	
	int n;
	for(;;)
	{
		cin>>n;
		if(n<=0)
		cout<<"´íÎó"<<endl;
		else
		{
			for(int i=1;i<=n;i=i+1)
			{
				for(int j=1;j<=i;j=j+1)
				{
					cout<<j<<"*"<<i<<"="<<(i*j)<<" ";
				}
				cout<<endl;
			}
		}
	}
}
