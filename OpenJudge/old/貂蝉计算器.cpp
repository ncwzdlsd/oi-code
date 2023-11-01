#include <iostream>
using namespace std; 

int main()
{
int h,m,n,t;
for(;;)
	{	
		cin>>h>>m>>n;
		t=3600*h+60*m+n;
		cout<<"t="<<t<<endl;
	}
}
