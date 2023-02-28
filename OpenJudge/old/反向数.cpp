#include <iostream>
using namespace std; 

int main()
{
	int a,b,c,m,n;
	for(;;)
	{
		cin>>m;
		a=(m-m%100)/100;
		b=(m%100-m%100%10)/10;
		c=m%100-10*b;
		n=100*c+10*b+a;
		cout<<"·´ÏòÊý="<<n<<endl; 
	}
}
