#include <iostream>
using namespace std;

int main()
{
	int k,i;
	cin>>k;
	int a=1,b=1,c;
	if(k<3)
		cout<<1<<endl;
	else
	{
		for(i=3;i<=k;i=i+1)
		{
			c=a+b;
			a=b;
			b=c;
		}
		cout<<c<<endl;
	}
}

