#include <bits/stdc++.h>
using namespace std;

int main()
{
	float x=1.0;
	double y=2.0;
	cout<<x/3.14159;
	cout<<x/3.14159*3.14159;
	x=x/3.14159;
	x=x*3.14159;
//	if(x==1.0)
	if(fabs(x - 1.0) < 0.000001)
	{
		printf("YES1\n");
	}
	else
	{
		printf("NO1\n");
	}
	
	y=sqrt(y);
	y=y*y;
//	if(y==2.0)
	if(fabs(y - 2.0) < 1e-6)
	{
		printf("YES2\n");
	}
	else
	{
		printf("NO2\n");
	}
	return 0;
} 
