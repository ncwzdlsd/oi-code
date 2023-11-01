#include <iostream>
using namespace std;

int main()
{
	int n;
	for(;;)
	{
		cin>>n;
		if(n<0)
			cout<<"´íÎó"<<endl;
		else
		{
			for(int i=1;i<=n;i=i+1)
			{
				for(int h=i;h<=n;h=h+1)
				{
					cout<<h;
				}
				for(int h=1;h<=i-1;h=h+1)
				{
					cout<<h;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
